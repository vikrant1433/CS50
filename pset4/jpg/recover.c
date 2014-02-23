/****************************************************************************
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 ***************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
typedef uint8_t  BYTE;


#define BLOCK 512

typedef struct
{
	BYTE f[4];

}
flag;

typedef struct
{
	BYTE b[BLOCK];
}
DATA;




int main(int argc, char const *argv[])
{
	// opening memory card
	FILE* fp_jpg = fopen("card.raw","r");

	if (!fp_jpg)
	{
		printf("Couldn't open %s\n","test.jpg");
		return -1;
	}

	// 512 byte of data
	DATA d;

	flag f1 = {{0xff, 0xd8, 0xff, 0xe0}};
	flag f2 = {{0xff, 0xd8, 0xff, 0xe1}};
	flag temp;

	// finding the starting of first jpeg
	while(fread(&temp,sizeof(flag),1,fp_jpg) == 1)
	{
		// fread(&temp,sizeof(flag),1,fp_jpg);
		if (!memcmp(&f1,&temp,sizeof(f1)) || !memcmp(&f2,&temp,sizeof(f2)))
			break;
		//fseek(fp_jpg, -(sizeof(f1)-sizeof(f1.f[0])), SEEK_CUR);
	}
	//moving cursor backward sizeof(flage) times
	fseek(fp_jpg, -sizeof(f1), SEEK_CUR);
	// file name of xxx.jpg
	int j = 0;
	char name[12];
	FILE* fnew = NULL;
	while(fread(&d,sizeof(DATA),1,fp_jpg) == 1)
	{

		if(!memcmp(&f1,&d,sizeof(f1)) || !memcmp(&f2,&d,sizeof(f2)))
		{
			if (j > 0)
				fclose(fnew);
			// creating new jpg file
			sprintf(name,"%.3d.jpg",j++);
			fnew = fopen(name,"w");

		}

		fwrite(&d,sizeof(DATA),1,fnew);

	}
	fclose(fp_jpg);
	if (fnew != NULL)
		fclose(fnew);
	return 0;
}

