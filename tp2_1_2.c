#include <stdio.h>

#define N 4
#define M 5

int main () {
    int f,c;
    double mt[N][M];
    double *p_mt = &mt[0][0];

    for(f = 0; f < N; f++) {

        for(c = 0; c < M; c++) {            
            printf("%lf ", *(p_mt + (f * M + c)));
        }
        printf("\n");
    }

    getchar();

    return 0;
}