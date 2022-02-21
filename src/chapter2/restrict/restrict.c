#include <stdio.h>

void swap(int *restrict x1, int *restrict x2) {
    int tmp = *x1;
    *x1 = *x2; 
    *x2 = tmp;
}

int main() {
    int a = 10, b = 20;
    swap(&a, &b);
    printf("a = %d, b = %d\n", a, b);

    return 0;
}
