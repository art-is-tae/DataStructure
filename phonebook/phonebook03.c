#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INIT_CAPACITY 3 // to testing array reallocate
#define BUFFER_SIZE 20

char **names; // names (global variable)
char **numbers; // phone numbers (global variable)

int capacity = INIT_CAPACITY; // size of array
int n = 0; // number of people in phone directory

void init_directory() {
  names = (char **) malloc(INIT_CAPACITY * sizeof(char *));
  numbers = (char **) malloc(INIT_CAPACITY * sizeof(char *));
}

int read_line(char str[], int limit) {
  int ch, i = 0;

  while ((ch = getchar()) != '\n') {
    if (i < limit - 1) {
      str[i++] = ch;
    }
  }
  
  str[i] = '\0';

  return i;
}

void add() {
  char buf1[BUFFER_SIZE], buf2[BUFFER_SIZE];
  scanf("%s", buf1);
  scanf("%s", buf2);

  int i = n - 1;
  while (i >= 0 && strcmp(names[i], buf1) > 0) { // bubble sort
    names[i + 1] = names[i];
    numbers[i + 1] = numbers[i];
    i--;
  }
  names[i + 1] = strdup(buf1);
  numbers[i + 1] = strdup(buf2);
  n++;

  printf("%s was added successfully.\n", buf1);
}

int search(char *name) {
  int i;
  for (i = 0; i < n; i++) {
    if (strcmp(name, names[i]) == 0) {
      return i;
    }
  }
  return -1;
}

void find() {
  char buf[BUFFER_SIZE];
  scanf("%s", buf);

  int index = search(buf);
  if (index == -1)
    printf("No person named '%s' exists.\n", buf);
  else 
    printf("%s\n", numbers[index]);
}

void status() {
  int i;
  for (i = 0; i < n; i++)
    printf("%s  %s\n", names[i], numbers[i]);

  printf("Total %d persons.\n", n);
}

void delete() {
  char buf[BUFFER_SIZE];
  scanf("%s", buf);

  int index = search(buf); // returns -1 if not exists
  if (index == -1) {
    printf("No person named '%s' exists.\n", buf);
    return;
  }
  int j = index;
  for (; j < n - 1; j++) {
    names[j] = names[j + 1];
    numbers[j] = names[j + 1];
  }
  n--;
  printf("'%s' was deleted successfully.\n", buf);
}

void load() {
  char fileName[BUFFER_SIZE];
  char buf1[BUFFER_SIZE];
  char buf2[BUFFER_SIZE];

  scanf("%s", fileName); // input file name

  FILE *fp = fopen(fileName, "r"); // to access the file, must open the file
  if (fp == NULL) {
    printf("Open failed.\n");
    return;
  }

  while ((fscanf(fp, "%s", buf1) != EOF)) { // iterate until the end of the file,
    fscanf(fp, "%s", buf2);                 // and save the name and number after load them
    names[n] = strdup(buf1);
    numbers[n] = strdup(buf2);
    n++;
  }

  fclose(fp); // must close the finished file
}

void save() {
  int i;
  char fileName[BUFFER_SIZE];

  scanf("%s", fileName);

  FILE *fp = fopen(fileName, "w");
  if (fp == NULL) {
    printf("Open failed.\n");
    return;
  }

  for (i = 0; i < n; i++) {
    fprintf(fp, "%s %s\n", names[i], numbers[i]);
  }
  fclose(fp);
}

char delim[] = " ";

int main() {

  init_directory();
  process_command();
  
  return 0;
}
