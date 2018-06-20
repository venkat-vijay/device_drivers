#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<errno.h>
#include<stdio.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <stdlib.h>


#define POWER_ON _IO('PN',0)
#define POWER_OFF _IO('PF',0)
#define PRINT_P _IO('PR',0)
#define APP_C _IO('AC',0)

 

void main() {
 int fd,cmd,ret_i,ret_r;
while(1)
{
	//fd = open("/home/vijay/Desktop/device_module/ioctl_assignment/app.txt", O_RDWR);
	ret_i = system("insmod $(pwd)/ioctl.ko");
	fd = open("/dev/vijay_null",O_RDWR);
	if (fd == -1)
	{
                printf("Error in opening file \n");
		break;
        }
	else
	{	
		printf("\n Device found : \n Device operation: \n \t 1) POWER ON \n \t 2) POWER OFF \n \t 3) PRINT \n \t 4) EXIT \n ");
		printf("Enter Operation : \b");
		scanf("%d",&cmd);
			
		switch (cmd)
		{
			case 1 :
				printf( "power on");
				ioctl(fd,POWER_ON);
				break;
			case 2 :
				printf( "power off");
				ioctl(fd,POWER_OFF);
				break;
        		case 3 :
				printf( "print");
				ioctl(fd,PRINT_P);
				break;
			case 4 : 
				printf("application exit \n");
				ioctl(fd,APP_C);
				exit(1);
				
			default:
				printf("please enter proper operation\n");
				break;
		}
		close(fd);	
	 }


// ioctl(fd,IOCTL_HELLO);  //ioctl call 

         

}
}
