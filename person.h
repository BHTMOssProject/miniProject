#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct person {
    char name[20];
    int age;
    int gender;
    char mbti[4];
} Person;

int createPerson(Person *p, int count);
int readPerson(Person *p, int count);
int updateData(Person *p, int count);
int deletePerson(Person *p, int count);