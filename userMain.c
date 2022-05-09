#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "person.h"
#include "manager.h"

int main() {
    Person *p;
    int count=0, menu = 0;

    p = (Person *)malloc(sizeof(Person) * MAX_SIZE);

    while (1) {
        menu = selectMenu();
        if (menu == 0) break;
        if (menu == 2 || menu == 3 || menu == 4) {
            if (count == 0) {
                printf("=> 사람 없음\n");
                continue;
            }
        }
        if (menu == 1) {
            createPerson(p, count);
            count++;
        }
        else if (menu == 2) {
            listPerson(p, count);
        }
        else if (menu == 3) {
            updateData(p, count);
        }
        else if (menu == 4) {
            deletePerson(p, count);
        }
    }
}