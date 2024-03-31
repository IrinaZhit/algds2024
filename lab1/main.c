#define CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <locale.h>
#include<string.h>

// вычисление минимума из трех чисел
int minim(int a, int b, int c) {
    int min = a;
    if (b < min)
        min = b;
    if (c < min)
        min = c;
    return min;
}

// вычисление расстояния d(x,y), алгоритм Левенштейна
int d(const char* x, const char* y) {
    int m = strlen(x);
    int n = strlen(y);
    int i, j, track, result;

    int** d = (int**)malloc((m + 1) * sizeof(int*));
    for (i = 0; i <= m; i++)
        d[i] = (int*)malloc((n + 1) * sizeof(int));// матрица

    for (i = 0; i <= m; i++)
        d[i][0] = i;
    for (j = 0; j <= n; j++)
        d[0][j] = j;

    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
            if (x[i - 1] == y[j - 1])
                track = 0;
            else track = 1;
            d[i][j] = minim(d[i - 1][j] + 1, // удаление 
                d[i][j - 1] + 1, // вставка
                d[i - 1][j - 1] + track); // замена
        }
    }
    result = d[m][n];
    for (int i = 0; i <= m; i++) {
        free(d[i]);
    }
    free(d);
    return result;
}

int main() {
    setlocale(LC_CTYPE, "Russian");

    char x[100];
    char y[100];

    printf("Введите x: ");
    fgets(x, sizeof(x), stdin);
    x[strcspn(x, "\n")] = 0;

    printf("Введите y: ");
    fgets(y, sizeof(y), stdin);
    y[strcspn(y, "\n")] = 0;

    printf("Минимальное число операций для преобразования '%s' в '%s': %d\n", x, y, d(x, y));
    return 0;
}
