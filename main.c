#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int firstWeekDay(int year) {
	int day;
	day = (((year - 1) * 365) + ((year - 1) / 4) - ((year - 1) / 100) + ((year) / 400) + 1) % 7;
	return day;
}

int main() {

	int year, daysInMonth, startingDay;
	int weekDay = 0;
	printf("\nPlease enter the year you wish to see calendar for: ");
	scanf("%d", &year);

	char* months[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	int monthDay[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
		monthDay[1] = 29;
	}

	startingDay = firstWeekDay(year);

	if (startingDay > 0 && startingDay <= 6) {
		startingDay--;
	} else if (startingDay == 0) {
		startingDay = 6;
	}

	for (int month = 0; month < 12; month++) {

		daysInMonth = monthDay[month];
		printf("\n\n               %s                 \n", months[month]);
		printf("\n  Mon  Tue  Wen  Thu  Fri  Sat  Sun \n");

		for (weekDay = 0; weekDay < startingDay; weekDay++) {
			printf("     ");
		}

		for (int day = 1; day <= daysInMonth; day++) {
			printf("%5d", day);

			if (++weekDay > 6) {
				printf("\n");
				weekDay = 0;
			}

			startingDay = weekDay;
		}
	}
}