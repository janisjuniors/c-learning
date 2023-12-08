#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Race {
  int numberOfLaps;
  int currentLap;
  char* firstPlaceDriverName;
  char* firstPlaceRaceCarColor; 
};

struct RaceCar {
  char* driverName;
  char* raceCarColor;
  int totalLapTime;
};

void printIntro(void) {
  printf("%s\n", "Welcome to our main event digital race fans!");
  printf("%s\n", "I hope everybody has their snacks because we are about to begin!");
}

void printCountDown(void) {
  printf("%s\n", "Racers Ready! In...");

  printf("%s\n", "5");
  printf("%s\n", "4");
  printf("%s\n", "3");
  printf("%s\n", "2");
  printf("%s\n", "1");

  printf("%s\n", "Race!");
}

void printFirstPlaceAfterLap(struct Race race) {
  printf("After lap number %d\n", race.currentLap);
  printf("First Place Is: %s in the %s race car!\n\n", race.firstPlaceDriverName, race.firstPlaceRaceCarColor);
}

void printCongratulation(struct Race race) {
  printf("Let's all congratulate %s in the %s race car for an amazing performance.\n", race.firstPlaceDriverName, race.firstPlaceRaceCarColor);
  printf("%s\n", "It truly was a great race and everybody have goodnight!");
}

int calculateTimeToCompleteLap(void) {
  int speed = rand() % 100 + 1;
  int acceleration = rand() % 100 + 1;
  int nerves = rand() % 100 + 1;

  return speed + acceleration + nerves;
}

void updateRaceCar(struct RaceCar* raceCar) {
  raceCar->totalLapTime += calculateTimeToCompleteLap();
}

void updateFirstPlace(struct Race* race, struct RaceCar* raceCar1, struct RaceCar* raceCar2) {
  if (raceCar1->totalLapTime <= raceCar2->totalLapTime) {
    race->firstPlaceDriverName = raceCar1->driverName;
    race->firstPlaceRaceCarColor = raceCar1->raceCarColor;
  } else {
    race->firstPlaceDriverName = raceCar2->driverName;
    race->firstPlaceRaceCarColor = raceCar2->raceCarColor;
  }
}

void startRace(struct RaceCar* raceCar1, struct RaceCar* raceCar2) {
  struct Race race = {5, 1, "", ""};

  for (int i = 0; i < race.numberOfLaps; i++) {
    updateRaceCar(raceCar1);
    updateRaceCar(raceCar2);
    updateFirstPlace(&race, raceCar1, raceCar2);
    printFirstPlaceAfterLap(race);
    race.currentLap++;
  }

  printCongratulation(race);
}

int main(void) {
  srand(time(0));

  struct RaceCar raceCar1 = {"Jack", "black", 0};
  struct RaceCar raceCar2 = {"John", "silver", 0};

  printIntro();
  printf("\n");
  
  printCountDown();
  printf("\n");

  startRace(&raceCar1, &raceCar2);
};