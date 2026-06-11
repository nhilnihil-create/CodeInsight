#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int arr[100];

int main(void){
    int N, t, sum = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &t);
        arr[i] = t;
        sum += t;
    }
    if (sum % 10 != 0) printf("%d\n", sum);
    else {
        sort(arr, arr+N);
        for (int i = 0; i < N; i++) {
            if (arr[i] % 10 != 0) {
                sum -= arr[i];
                break;
            }
        }
        (sum % 10 == 0) ? printf("%d\n", 0) : printf("%d\n", sum);
    }
    return 0;
}
