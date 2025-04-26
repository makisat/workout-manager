#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct {
  char* year, month, day;

} Date;

typedef struct {
  char *name;
  uint8_t set_length;
  uint8_t* sets_reps;

} Exercise;

typedef struct {
  Date date;
  Exercise* exercises;

} Workout;

typedef struct {
  char* username;
  Workout* workouts;

} User;

User createUser(char *username) {
  return (User) {.username = username};
}

void addWorkout(User *user, Workout workout) {}

void addExercise(Workout *workout, Exercise exercise) {}

int addSet(Exercise *exercise, uint8_t reps) {
  if (exercise->set_length == 0) {
    exercise->set_length = 1;
    exercise->sets_reps = (uint8_t *)malloc(sizeof(uint8_t));
    if (exercise->sets_reps == NULL) {
      printf("memory allocation failed\n");
      return 1;
    }
    exercise->sets_reps[0] = reps;
    return 0;
  }

  exercise->set_length++;
  uint8_t* temp_ptr = (uint8_t*) realloc(exercise->sets_reps, sizeof(uint8_t) * exercise->set_length);
  if (exercise->sets_reps == NULL) {
    printf("memory allocation failed\n");
    exercise->set_length--;
    return 1;
  }
  exercise->sets_reps = temp_ptr;
  exercise->sets_reps[exercise->set_length - 1] = reps;
  return 0;
}

int main() {

  Exercise exe = {.name = "test"};

  if (addSet(&exe, 10) == 1) {
    printf("failed add set\n");
    return 1;
  }

  if (addSet(&exe, 11) == 1) {
    printf("failed add set\n");
    return 1;
  }

  for (int i = 0; i < exe.set_length; i++) {
    printf("%d\n", exe.sets_reps[i]);
  }

  free(exe.sets_reps);

  return 0;
}
