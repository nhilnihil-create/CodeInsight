#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    long h,w,a,b;
    scanf("%ld %ld %ld %ld", &h, &w, &a, &b);
    if(a * b == 1){
        printf("No");
        return 0;
    }
    long n = 999999999 / (a * b - 1);
    long m = -n * (a * b - 1) - 1;
    if( (m - n) * (h / a) * (w / b) + n * h * w <= 0){
        printf("No");
    } else {
        printf("Yes\n");
        for(int i = 1; i < h+1; i++){
            for(int j = 1; j < w+1; j++){
                if(i % a == 0 && j % b == 0){
                    printf("%ld ", m);
                } else {
                    printf("%ld ", n);
                }
            }
            printf("\n");
        }
    }
    
    return 0;
}
