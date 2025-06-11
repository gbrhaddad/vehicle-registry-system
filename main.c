#include "car.h"
int main()
{
	vehicle_t vektor[q];
	int num = -1;
	num = Read(vektor, num);
	menu(vektor, num);
	return 0;
}
void menu(vehicle_t vektor[], int num)
{
	int choice;
	char text[10] = { 0 };
	while (1)
	{
		printf("Choose:\n1- Add a vehicle.\n2- Remove a vehicle.\n3- Sort by car brand.\n4- Print information about a vehcile.\n5- Print the complete vehicle register.\n6- Exit.\n ");
		fgets(text, 9, stdin);
		choice = atoi(text);
		switch (choice) {
		case 1:

			num++;
			if (num < q)
			{
				Add(vektor, num);
			}
			else
			{
				printf("There is already 10 cars ");
				num--;
			}
			menu(vektor, num);
			break;

		case 2:
			if (num >= 0)
			{
				num = Remove(vektor, num);
			}
			else
			{
				printf("No cars are registered");
			}
			menu(vektor, num);
			break;
		case 3:
			if (num >= 0)
			{
				Sort(vektor, num);
			}
			else
			{
				printf("No cars are registered\n");
			}
			menu(vektor, num);

		case 4:
			if (num >= 0)
			{
				Print(vektor, num);
			}
			else
			{
				printf("No cars found\n");
			}
			menu(vektor, num);
			break;
		case 5:
			if (num >= 0)
			{
				PrintAll(vektor, num);
			}
			else
			{
				printf("No cars found\n");
			}
			menu(vektor, num);
			break;
		case 6:
			Write(vektor, num);
			printf("Exit\n");
			exit(0);
		default:
			if (!isdigit(choice))
			{
				printf("Wrong Choice, choose again\n");
				menu(vektor, num);
			}
		}
	}
}
void Add(vehicle_t vektor[], int num)
{
	char list[q];
	printf("Write type of the vehcile:\n");
	fgets(vektor[num].type, length - 1, stdin);
	printf("write the name:\n");
	fgets(vektor[num].owner.name, length - 1, stdin);
	printf("Write your old\n");
	fgets(list, q - 1, stdin);
	vektor[num].owner.old = atoi(list);
	printf("Write brand of the vehicle:\n");
	fgets(vektor[num].brand, length - 1, stdin);
	printf("write the Regnum of the vehicle :\n");
	fgets(vektor[num].regNum, length - 1, stdin);
}
int Remove(vehicle_t vektor[], int num)
{
	int del, i;
	char list[q];
	printf("which car should be removed:\n");
	fgets(list, q - 1, stdin);
	del = atoi(list);
	if (del > 0 && del <= num + 1)
	{
		del--;
		for (i = del; i <= num; i++)
		{
			vektor[i] = vektor[i + 1];
		}
		num--;
	}
	else
	{
		printf("The car dose not exist!\n");
	}
	return num;
}
void Sort(vehicle_t vektor[], int num)
{
	int i, j;
	vehicle_t temp;
	for (i = 1; i <= num; i++)
	{
		for (j = 0; j <= num - i; j++)
		{
			if (strcasecmp(vektor[j].brand, vektor[j + 1].brand) > 0)
			{
				temp = vektor[j];
				vektor[j] = vektor[j + 1];
				vektor[j + 1] = temp;
			}
		}
	}
}
void Print(vehicle_t vektor[], int num)
{
	int key;
	char list[q];
	printf("Which can do you want to print:\n");
	fgets(list, q - 1, stdin);
	key = atoi(list);
	if (key > 0 && key <= num + 1)
	{
		key--;
		printf(" vehicle_tstyp: %s\n", vektor[key].type);
		printf(" agaresnamn: %s\n", vektor[key].owner.name);
		printf(" agares�lder: %d\n", vektor[key].owner.old);
		printf(" vehicle_tsm�rke: %s\n", vektor[key].brand);
		printf(" vehicle_tsregnum: %s\n", vektor[key].regNum);
	}
	else
	{
		printf("vehicle hittades inte\n");
	}
}
void PrintAll(vehicle_t vektor[], int num)
{
	int i;
	for (i = 0; i <= num; i++)
	{
		printf("%d . vehicle_tstyp: %s\n", i + 1, vektor[i].type);
		printf("%d . agaresnamn: %s\n", i + 1, vektor[i].owner.name);
		printf("%d . agares�lder: %d\n", i + 1, vektor[i].owner.old);
		printf("%d . vehicle_tsm�rke: %s\n", i + 1, vektor[i].brand);
		printf("%d . vehicle_tsregnum: %s\n", i + 1, vektor[i].regNum);
	}
}