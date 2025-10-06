
#include <stdio.h>

int main() {
    int age = 0;
    char a = ' ';

    printf("Enter your age: ");
    fflush(stdout);
    scanf(" %d", &age);

    // Clear leftover newline from input buffer
    getchar(); // This consumes the '\n' left by scanf

    printf("Press any key to continue: ");
    fflush(stdout);
    a = getchar(); // Now this waits for actual key press

    if (a == 'a') {
        printf("You really pressed the key I thought—very nice:)\n");
} else {
        printf("You pressed: %c\n", a);
}

    printf("You are %d years old, that's very good. Nice to meet you!!\n", age);
    printf("\n\n\n\n[Program Finished] 0.0s:) \n");

    return 0;
}
