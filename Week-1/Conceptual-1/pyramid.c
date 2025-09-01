#include <stdio.h>
#include <stdbool.h>

int main() {
    int number;
    bool isPrime = true;
    scanf("%d", &number);
    if (number < 2) {
        isPrime = false;  
    } else {
        for (int i = 2; i * i <= number; i++) {
            if (number % i == 0) {
                isPrime = false;
                break;
            }
        }
    }

    if (isPrime) {
        printf("%d is a Prime Number\n", number);
    } else {
        printf("%d is Not a Prime Number\n", number);
    }

    return 0;
}
