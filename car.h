#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define length 60
#define q 10
void menu();
void Add();
int Remove();
void Sort();
void Print();
void PrintAll();
void Write();
int Read();

struct person
{
	char name[length];
	int old;
};
typedef struct person person_t;
struct vehicle
{
	char type[length];
	char brand[length];
	char regNum[length];
	person_t owner;
};
typedef struct vehicle vehicle_t;