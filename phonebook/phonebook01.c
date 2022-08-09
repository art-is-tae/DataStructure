#include <stdio.h>
#include <string.h>

#define CAPACITY 100 // maximum 100 persons
#define BUFFER_SIZE 20

char *names[CAPACITY]; // names (global variable)
char *numbers[CAPACITY]; // phone numbers (global variable)
int n = 0; // number of people in phone directory

void add() {
  char buf1[BUFFER_SIZE], buf2[BUFFER_SIZE];
  scanf("%s", buf1);
  scanf("%s", buf2);

  names[n] = strdup(buf1);
  numbers[n] = strdup(buf2);
  n++;

  printf("%s was added successfully.\n", buf1);
}

/*
char *strdup(char *s) { // 매개변수로 받은 하나의 문자열을 그곳에 복사하여 반환
  char *p;
  p = (char *)malloc(strlen(s)+1);
  if (p != NULL)
    strcpy(p, s);
  return p;
}
*/

void find() {
  char buf[BUFFER_SIZE];
  scanf("%s", buf);

  int i;
  for (i=0; i<n; i++) {
    if (strcmp(buf, names[i]) == 0) {
      printf("%s\n", numbers[i]);
      return;
    }
    printf("No person named '%s' exists.\n", buf);
  }
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

  int i;
  for (i = 0; i < n; i++) {
    if (strcmp(buf, names[i]) == 0) {
      names[i] = names[n - 1]; // move last person to deleted position
      numbers[i] = numbers[n - 1]; // move last person to deleted position
      n--;

      printf("'%s' was deleted successfully.\n", buf);
      return;
    }
  }
  printf("No person named '%s' exists.\n", buf);
}

int main() {
  char command[BUFFER_SIZE];

  while (1) {
    printf("$ ");
    scanf("%s", command);

    if (strcmp(command, "add") == 0)
      add();
    else if (strcmp(command, "find") == 0)
      find();
    else if (strcmp(command, "status") == 0)
      status();
    else if (strcmp(command, "delete") == 0)
      delete();
    else if (strcmp(command, "exit") == 0)
      break;
  }
  return 0;
}
