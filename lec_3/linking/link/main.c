/*
*  Video Lecture: 03
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*/

#include <stdio.h>

int x;

void swap();
int buf[2] = {1,2};
int main()
{
	swap();
	printf("buf[0]= %d, buf[1]= %d \n",buf[0], buf[1]);
    printf("inside main and x value is %d", x);
	return 0;
}
