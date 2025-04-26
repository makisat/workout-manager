#include <stdio.h>

typedef struct {
  char* year, month, day;

} Date;

typedef struct {
  char* username;
  Workout* workouts;

} User;

typedef struct {
  Date date;
  Exercise* exercises;

} Workout;

typedef struct {
  char* name;
  unsigned char sets;
  unsigned char reps;

} Exercise;



int main() {



  return 0;
}
