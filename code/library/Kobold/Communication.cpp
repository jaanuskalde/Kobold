/*

   Kobold communication, uses timer2

*/

#include "WProgram.h"
#include "Communication.h"
#include <util/parity.h> 


//byte what is being sent to the world
byte toSend = 0;
volatile byte address;

//tmp vars for communication
byte send_tmp = 0;//first two bits are for flags
byte rec_tmp[] = {0,0,0,0};
int dist[] = {0,0,0,0};
byte get[] = {0,0,0,0};
int last[4][20];



void initCommunication(byte _address)
{
   address = _address;
//   eelmine[0] = eelmine[1] = eelmine[2] = eelmine[3] = 0;
//   kaugus[0] = kaugus[1] = kaugus[2] = kaugus[3] = 0;

   pinMode(IR, OUTPUT);
   IR_OFF;

   bitSet(TCCR2A, WGM21);
   bitSet(TCCR2B, CS22);
   bitSet(TCCR2B, CS20);
   OCR2A = 255;
   bitSet(TIMSK2, OCIE2A);
}

void send(byte what)
{
   send_tmp = 0;
   toSend = what;
}

void distance(int data[4])
{

}

/*
   Send out modulated signal. 
*/

void ISR_rec(int who, int what, int str);


ISR(TIMER2_COMPA_vect)
{
   for (unsigned char sen_num = 0; sen_num < 4; sen_num ++)
   {
      //calculate the minimum of last three
      int low = last[sen_num][0];
      if (last[sen_num][1] < low) low = last[sen_num][1];
      if (sensor[sen_num] < low) low = sensor[sen_num];

      //if we get an rising edge
      if ((sensor[sen_num] > low + low / ir_min_perc) && (sensor[sen_num] > low + ir_min_diff))
      {
         //and we are not recing and we got a rising edge, start recieving
         if (rec_tmp[sen_num] == 0)
         {
            rec_tmp[sen_num]=1;
            get[sen_num]=0;
         }
      }
      else
      {
         if ((last[sen_num][0] > low + low / ir_min_perc) && (last[sen_num][0] > low + ir_min_diff))
         {
            if ((last[sen_num][1] > low + low / ir_min_perc) && (last[sen_num][1] > low + ir_min_diff))
            {
               bitSet(get[sen_num], rec_tmp[sen_num]-1);
            }
            rec_tmp[sen_num] ++;
         }
         else rec_tmp[sen_num] = 0;
      }

      //we have seen 8 bits
      if (rec_tmp[sen_num] == 7)
      {
         rec_tmp[sen_num] = 0;
         ISR_rec(sen_num, get[sen_num], last[sen_num][0]-low);
      }

      //shift memories
      last[sen_num][1] = last[sen_num][0];
      last[sen_num][0] = sensor[sen_num];
   }

      /*
      //old debug stuff
      Serial.print((last[1][0]-low), DEC);
      Serial.print(" : ");
      Serial.print(get[1], DEC);
      for (int q = 19; q>0; q--)
      {
         Serial.print(" : ");
         Serial.print(last[1][q], DEC);
      }*/

   /*
      * If you put something in "toSend" variable then it will be fired away with IR leds.
      * uses freaky encoding. 0 means new bit, 1 means 0, 11 means 1
      * At speed 1kHz.
   */
   if (toSend != 0)
   {
      if (bitRead(send_tmp, 7))
      {
         IR_OFF;
         send_tmp &= B00111111;
         send_tmp ++;
         
         if (send_tmp == 9) toSend = 0;
      }
      else
      {
         IR_ON;
         if (bitRead(send_tmp, 6))
         {
            bitSet(send_tmp, 7);
            bitClear(send_tmp, 6);
         }
         else
         {
            if (bitRead(toSend, send_tmp & B00111111))
            {
               bitSet(send_tmp, 6);
            }
            else
            {
               bitSet(send_tmp, 7);
            }
         }
      }
   }
   digitalWrite(MOD_A, LOW);
}
