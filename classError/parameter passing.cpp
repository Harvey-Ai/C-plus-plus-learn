#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// to modify the pointer itself, must change use reference or second level pointer

void GetMemory(char *&p,int num)
{
	 p=(char*)malloc(sizeof(char) * num);
}

int main(int argc, char *argv[])
{
	char *str=NULL;
	char s[100];
	GetMemory(str, 100);
	return 0;
}
