#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MONTHS 12

char *mname[] = {"January", "February", "March", "April", "May", "June", "July",
				 "August", "September", "October", "November", "December"};
				 
int leap[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, INT_MAX};
int regular[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, INT_MAX};

int *days[]={leap, regular};

void datemonth(int day, int year, int *pdate, int *pmonth)
{	
	int normal=1, *pday;
	if(year%4) normal--;
	pday = days[normal];
	while (day>*pday) day-=*pday++;
	*pdate = day;
	*pmonth = pday-days[normal];
}

char *name(int month){
	return mname[month];
}

int main(int argc, char *argv[]){

	int day,year,date,month;
	
	if (argc!=3){
			printf("usage: %s <day> <year>\n", argv[0]);
			return 1;
	}
	
day = atoi(argv[1]);
year = atoi(argv[2]);

datemonth(day, year, &date, &month);

if(date>0 && month<MONTHS){
	printf("%d %s\n", date, name(month));
	return 0;
}
else{
	printf("an out of range day\n");
	return 1;
}
}
