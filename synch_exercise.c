#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int somatorio = 0;
void *sigma (void *args);
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int main(void) {
    int length = 0, n = 0, i = 0, j = 0;
    scanf("%d", &length);
    int th_quantity = length;
    int matrix[length][length];
    pthread_t threads[th_quantity];

    for (i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            scanf("%d", &n);
            matrix[i][j] = n;
        }
    }

    for (i = 0; i < length; i++) {
        int *the_line = malloc(length * sizeof(int));
        for (j = 0; j < length; j++) {
            the_line[j] = matrix[i][j];
        }
        pthread_create(&(threads[i]), NULL, sigma, (void *)the_line);
    }

    for (i = 0; i < length; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("%d\n", somatorio);
    return 0;
}

void *sigma(void *args) {
    int k;
    int *arr = (int *)args;
    int length = sizeof(*arr);
    int sigma_line = 0;
    for (k = 0; k < length; k++) {
        sigma_line += arr[k];
    }
    pthread_mutex_lock(&mutex);
    somatorio += sigma_line;
    pthread_mutex_unlock(&mutex);
    return args;
}