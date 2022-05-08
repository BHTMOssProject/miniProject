#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "person.h"

int main() {
    Person *p;
    int count, menu = 0;

    p = (Person *)malloc(sizeof(Person) * MAX_SIZE);

    while (1) {
        menu = selectMenu();
        if (menu == 0) break;
        if (menu == 2 || menu == 3 || menu == 4) {
            if (count == 0) {
                printf("=> 상품 없음\n");
                continue;
            }
        }
        if (menu == 1) {
            createProduct(p, count);
            count++;
        }
        else if (menu == 2) {
            listProduct(p, count);
        }
        else if (menu == 3) {
            updateProduct(p, count);
        }
        else if (menu == 4) {
            deleteProduct(p, count);
        }
    }
}