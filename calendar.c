#include <stdio.h>
#include <stdbool.h>

#define DATE_BYTES 3

int DAYS_IN_MONTH[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool is_leap_year(int year) {
  return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

void add_days_to_date(int *dd, int *mm, int *yy, int days_left_to_add) {
  int days_left_in_month;

  while (days_left_to_add > 0) {
    int february_month_index = 2;
    days_left_in_month = DAYS_IN_MONTH[*mm] - *dd;

    if (*mm == february_month_index && is_leap_year(*yy)) {
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
  int dd, mm, yy, days_left_to_add;

  printf("%s", "Please enter a date between the years 1800 and 10000 in the format dd.mm.yy: ");
  scanf("%d.%d.%d", &dd, &mm, &yy);

  printf("%s", "Please provide a number of days to add to the previously entered date: ");
  scanf("%d", &days_left_to_add);

  add_days_to_date(&dd, &mm, &yy, days_left_to_add);

  char formatted_dd[DATE_BYTES];
  sprintf(formatted_dd, dd < 10 ? "0%d" : "%d", dd);

  char formatted_mm[DATE_BYTES];
  sprintf(formatted_mm, mm < 10 ? "0%d" : "%d", mm);

  printf( "New date - %s.%s.%d \n", formatted_dd, formatted_mm, yy);
}