#include "car.h"
void Write(vehicle_t vektor[], int num)
{
	int i;
	FILE* FW = fopen("File.txt", "w");
	if (!FW)
	{
		printf("Filen kan inte �ppnas!\n");
	}
	else
	{
		for (i = 0; i <= num; i++)
		{
			fprintf(FW, "%s\t", vektor[i].owner.name);
			fprintf(FW, "%d\t", vektor[i].owner.old);
			fprintf(FW, "%s\t", vektor[i].type);
			fprintf(FW, "%s\t", vektor[i].brand);
			fprintf(FW, "%s\n", vektor[i].regNum);
		}
		fclose(FW);
	}
}
int Read(vehicle_t vektor[], int num)
{
	FILE* FR;
	int read;
	FR = fopen("File.txt", "r");
	if (!FR)
	{
		printf("Filen kan inte �ppnas!\n");
	}
	else
	{
		do {
			vehicle_t fileRead;
			read = fscanf(FR, "%s %d %s %s %s",
				fileRead.owner.name, &fileRead.owner.old, fileRead.type, fileRead.brand, fileRead.regNum);
			if (read != EOF)
			{
				num++;
				vektor[num] = fileRead;
			}
		} while (read != EOF);
		fclose(FR);
	}
	return num;
}