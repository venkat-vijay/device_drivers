#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<errno.h>
#include<stdio.h>
#include <unistd.h>
#include <sys/ioctl.h>


#define IOC_MAGIC 'k'
#define IOCTL_HELLO _IO(IOC_MAGIC,0) 

void main() {
 int fd;
        fd = open("/dev/vijay_null", O_RDWR);

        if (fd == -1)
        {
                printf("Error in opening file \n");
        }

 ioctl(fd,IOCTL_HELLO);  //ioctl call 

         close(fd);
}
