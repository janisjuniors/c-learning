#include <stdio.h>
#include <stdbool.h>

bool is_leap_year(int year) {
  return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

int DAYS_IN_MONTH[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int FEBRUARY_INDEX = 2;

void add_days_to_date(int *dd, int *mm, int *yy, int days_left_to_add) {
  int days_left_in_month;

  while (days_left_to_add > 0) {
    days_left_in_month = DAYS_IN_MONTH[*mm] - *dd;

    if (*mm == FEBRUARY_INDEX && is_leap_year(*yy)) {
      days_left_in_month++;
    }

    if (days_left_to_add > days_left_in_month) {
      days_left_to_add -= days_left_in_month + 1;
      *dd = 1;

      if (*mm == 12) {
        *mm = 1;
        *yy = *yy + 1;
      } else {
        *mm = *mm + 1;
      }
    } else {
      *dd = *dd + days_left_to_add;
      days_left_to_add = 0;
    }
  }
}

int main(void) {
  int dd;
  int mm;
  int yy;
  int days_left_to_add;

  printf("%s", "Please enter a date between the years 1800 and 10000 in the format dd.mm.yy: ");
  scanf("%d.%d.%d", &dd, &mm, &yy);

  printf("%s", "Please provide a number of days to add to this date: ");
  scanf("%d", &days_left_to_add);

  add_days_to_date(&dd, &mm, &yy, days_left_to_add);

  printf("New date - %d.%d.%d \n", dd, mm, yy);
}