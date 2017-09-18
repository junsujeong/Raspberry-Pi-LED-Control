#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int ledControl(int gpio)
{
   int fd;
   char buf[BUFSIZ];

   //Getting GPIO ready 
   fd = open("/sys/class/gpio/export",O_WRONLY);
   sprintf(buf, "%d", gpio);
   write(fd, buf, strlen(buf));
   close(fd);

   //Setting direction of GPIO 
   sprintf(buf, "/sys/class/gpio/gpio%d/direction", gpio);
   fd = open (buf, O_WRONLY);
   write(fd, "out", 4);  //since LED only gives output use ¨out¨
   close(fd);

   //Set the value to 1
   sprintf(buf, "/sys/class/gpio/gpio%d/value", gpio);
   fd = open (buf, O_WRONLY);
   write(fd, "1", 2); 
   close(fd);

   getchar(); //

   fd = open("/sys/class/gpio/gpio%d/unexport", O_WRONLY);
   sprintf (buf, "%d", gpio);
   write (fd, buf, strlen(buf));
   close (fd);

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

   ledControl(gno);

   return 0;
}

