#include <stdio.h>

void factorize(int n) {
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            printf("%d=%d*%d\n", n, i, n / i);
            return;
        }
    }
    printf("%d=%d*%d\n", n, 1, n);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("File not found or cannot be opened.\n");
        return 1;
    }

    int number;
    while (fscanf(file, "%d", &number) == 1) {
        factorize(number);
    }

    fclose(file);

    return 0;
}

