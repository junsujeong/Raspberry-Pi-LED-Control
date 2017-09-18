#include <wiringPi.h>
#include <stdio.h>

int ledControl(int gpio)
{
   int i;
   pinMode(gpio, OUTPUT); //set output of the pin
   for (i = 0; i < 5; i++)
       {
      digitalWrite (gpio, HIGH); //write High (1), turn on the LED
      delay(1000);
      digitalWrite (gpio, LOW); //write Low (0), turn on the LED
      delay(1000);
       } ;
   return 0;
}

int main(int argc, char** argv)
{
  int gno;
   
   if(argc < 2)
       {   
      printf("Usage : %s GPIO_NO\n", argv[0]);
      return -1;
       }
   gno = atoi(argv[1]);
   wiringPiSetup(); // resets wiringPi
   ledControl(gno);

   return 0;
}
