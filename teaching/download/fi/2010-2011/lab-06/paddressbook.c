
#include <stdio.h>

#define FALSE 0
#define TRUE 1

#define MALE 'M'
#define FEMALE 'F'

#define MAX_NAME_LENGTH 16
#define MAX_SURNAME_LENGTH 16
#define CF_LENGTH 16

#define ADDRESS_BOOK_SIZE 30

#define MENU_INSERT_NEW_PERSON 1
#define MENU_GET_AVERAGE_AGE 2
#define MENU_COUNT_PEOPLE 3
#define MENU_SAVE 4
#define MENU_LOAD 5
#define MENU_SHOW 6
#define MENU_EXIT 7

#define DATA_FILE "addresses.txt"
#define RECORD_FORMAT "%s %s %s %u %c"

typedef char gender_t;

typedef struct {
  char name[MAX_NAME_LENGTH + 1];
  char surname[MAX_SURNAME_LENGTH + 1];
  char cf[CF_LENGTH + 1];
  unsigned int age;
  gender_t gender;
} person_t;


/**
 * A simple address book, with a file back-end.
 */
int main(int argc, char* argv[]) {
  person_t people[ADDRESS_BOOK_SIZE], read_person;
  unsigned int chose, i, males, females, next = 0;
  float average;
  FILE* file;

  do {
    printf("\nWelcome to paddress book, please select an option!\n"
           "\n"
           "%u - Insert a new person\n"
           "%u - Get the average age\n"
           "%u - Count people by gender\n"
           "%u - Save address book to file\n"
           "%u - Load address book from file\n"
           "%u - Show address book\n"
           "%u - Exit from paddressbook\n"
           "Chose: ",
           MENU_INSERT_NEW_PERSON,
           MENU_GET_AVERAGE_AGE,
           MENU_COUNT_PEOPLE,
           MENU_SAVE,
           MENU_LOAD,
           MENU_SHOW,
           MENU_EXIT);
    scanf("%u%*c", &chose);

    switch(chose) {
    case MENU_INSERT_NEW_PERSON:
      printf("\nInsert a new person\n");

      if(next >= ADDRESS_BOOK_SIZE) {
        printf("The address book is full!\n");
        break;
      }

      printf("Name (max %u chars): ", MAX_NAME_LENGTH);
      gets(people[next].name);

      printf("Surname (max %u chars): ", MAX_SURNAME_LENGTH);
      gets(people[next].surname);

      printf("Codice fiscale (exactly %u chars): ", CF_LENGTH);
      gets(people[next].cf);

      printf("Age: ");
      scanf("%u%*c", &people[next].age);

      do {
        printf("Gender (M or F): ");
        scanf("%c%*c", &people[next].gender);
      } while(people[next].gender != MALE && people[next].gender != FEMALE);

      next++;

      break;

    case MENU_GET_AVERAGE_AGE:
      average = 0;
      for(i = 0; i < next; i++)
        average += (people[i].age / (float) next);

      printf("\nThe average age, above %u people, is %f\n", next, average);
      break;

    case MENU_COUNT_PEOPLE:
      males = 0;
      for(i = 0; i < next; i++)
        if(people[i].gender == MALE)
          males++;
      females = next - males;

      printf("\nThere are %u people: %u males and %u females\n",
             next, males, females);
      break;

    case MENU_SAVE:
      printf("\n");

      file = fopen(DATA_FILE, "w");

      if(file == NULL) {
        printf("Error opening data file %s\n", DATA_FILE);
        break;
      }

      for(i = 0; i < next; i++) {
        fprintf(file, RECORD_FORMAT,
                people[i].name, people[i].surname, people[i].cf,
                people[i].age, people[i].gender);
        fprintf(file, "\n");
      }

      fclose(file);

      printf("Addresses saved into the %s file\n", DATA_FILE);

      break;

    case MENU_LOAD:
      printf("\n");

      file = fopen(DATA_FILE, "r");
      
      if(file == NULL) {
        printf("Error opening data file %s\n", DATA_FILE);
        break;
      }

      next = 0;
      fscanf(file, RECORD_FORMAT,
             &read_person.name, &read_person.surname, &read_person.cf,
             &read_person.age, &read_person.gender);

      while(next < ADDRESS_BOOK_SIZE && feof(file) == 0) {
        people[next] = read_person;
        next++;

        fscanf(file, RECORD_FORMAT,
               &read_person.name, &read_person.surname, &read_person.cf,
               &read_person.age, &read_person.gender);
      }

      fclose(file);

      printf("Addresses loaded from the %s file\n", DATA_FILE);

      break;
    case MENU_SHOW:
      printf("Current Content:\n");
      for(i = 0; i < next; i++) {
        printf(RECORD_FORMAT,
                people[i].name, people[i].surname, people[i].cf,
                people[i].age, people[i].gender);
        printf("\n");
      }
    case MENU_EXIT:
      printf("\nSee you later\n");
      break;

    default:
      printf("Unknown chose: %u\n", chose);
    }
  } while(chose != MENU_EXIT);

  return 0;
}
