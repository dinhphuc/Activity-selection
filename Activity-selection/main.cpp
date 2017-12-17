#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct Activity
{
	int StartTime, EndTime;
};

void ActivitySortMaxJob(Activity a[], int n)
{
	Activity b[100];
	int i, m = a[0].EndTime, exp = 1;
	for (i = 1; i < n; i++)
	{
		if (a[i].EndTime > m)
			m = a[i].EndTime;
	}
	while (m / exp > 0)
	{
		int bucket[10] = { 0 };
		for (i = 0; i < n; i++)
			bucket[a[i].EndTime / exp % 10]++;
		for (i = 1; i < 10; i++)
			bucket[i] += bucket[i - 1];
		for (i = n - 1; i >= 0; i--)
			b[--bucket[a[i].EndTime / exp % 10]] = a[i];
		for (i = 0; i < n; i++)
			a[i] = b[i];
		exp *= 10;
	}
}
void ActivitySelectionMaxJob(Activity act[], int n)
{
	ActivitySortMaxJob(act, n);
	int i = 0;
	printf("Activity %d : (%d-%d)\n", i + 1, act[i].StartTime, act[i].EndTime);
	for (int j = 1; j < n; j++)
	{

		if (act[j].StartTime >= act[i].EndTime)
		{
			printf("Activity %d : (%d-%d)\n", j + 1, act[j].StartTime, act[j].EndTime);
			i = j;
		}
	}
}

void ActivitySortTimeMax(Activity a[], int n)
{
	Activity b[100];
	int i, m = (a[0].EndTime- a[0].StartTime), exp = 1;
	for (i = 1; i < n; i++)
	{
		if ((a[i].EndTime - a[i].StartTime) < m)
			m = (a[i].EndTime - a[i].StartTime);
	}
	while (m / exp > 0)
	{
		int bucket[10] = { 0 };
		for (i = 0; i < n; i++)
			bucket[(a[i].EndTime - a[i].StartTime) / exp % 10]++;
		for (i = 1; i < 10; i++)
			bucket[i] += bucket[i - 1];
		for (i = n - 1; i >= 0; i--)
			b[--bucket[(a[i].EndTime - a[i].StartTime) / exp % 10]] = a[i];
		for (i = 0; i < n; i++)
		{
			a[i] = b[n-i-1];
		}
			
		exp *= 10;
	}
}

void ActivitySelectionMaxTime(Activity act[], int n)
{
	ActivitySortTimeMax(act, n);
	int i = 0;
	printf("Activity %d : (%d-%d)\n", i + 1, act[i].StartTime, act[i].EndTime);
	for (int j = 1; j < n; j++)
	{

		if (act[j].StartTime >= act[i].EndTime)
		{
			printf("Activity %d : (%d-%d)\n", j + 1, act[j].StartTime, act[j].EndTime);
			i = j;
		}
	}
}

void Input(Activity act[], int n)
{
	for (int i = 0; i < n; i++)
	{
		act[i].EndTime= rand() % 101 + 10;
		act[i].StartTime = rand() % 101 + 10;
	}
}
void OutPut(Activity act[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("Activity %d : (%d-%d)\n",i+1,act[i].StartTime, act[i].EndTime);
	}
}
void main()
{
	Activity act[] = {{5, 9}, { 1, 2 }, { 3, 4 }, { 0, 6 },{ 5, 7 }, { 8, 9 }};
	//Activity act[] = { { 1,2 },{ 1,3 },{ 0,4 },{ 3,5 },{ 4,5 },{ 4,6 },{ 5,8 },{ 2,9 } };

	int n = sizeof(act)/sizeof(act[0]);
	//ActivitySelectionMaxJob(act, n);
	//ActivitySelectionMaxTime(act, n);
	//ActivitySortTimeMax(act, n);
	//OutPut(act, n);
	_getch();
}