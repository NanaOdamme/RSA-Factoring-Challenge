#include <stdio.h>
#include <inttypes.h>
#include <time.h>

void factorize(uint64_t n) {
    uint64_t p = 2;

    printf("%" PRIu64 "=", n);

    while (p * p <= n) {
        if (n % p == 0) {
            uint64_t q = n / p;
            if (p <= q) {
                printf("%" PRIu64 "*%" PRIu64 "\n", p, q);
            } else {
                printf("%" PRIu64 "*%" PRIu64 "\n", q, p);
            }
            return;
        }
        p++;
    }

    printf("%" PRIu64 " * %d\n", n, 1);
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

    uint64_t number;
    while (fscanf(file, "%" SCNu64, &number) == 1) {
        clock_t start_time = clock();
        factorize(number);
        clock_t end_time = clock();
        double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

        if (elapsed_time >= 1.0) {
            printf("Time limit exceeded for input %" PRIu64 "\n", number);
            break;
        }
    }

    fclose(file);

    return 0;
}

