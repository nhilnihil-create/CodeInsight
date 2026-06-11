#include<bits/stdc++.h>
using namespace std;

int N;
int A[100010];

int main() {
    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    sort(A, A + N);

    for(int i = N - 1; i >= 0; i--) {
        if(A[i] == N - i) {
            int j = i;
            while(j && A[j - 1] == A[j]) j--;

            if((i - j) % 2) {
                printf("First");
                return 0;
            }
            else {
                printf("Second");
                return 0;
            }
        }
        else if(i && A[i - 1] == N - i) {
            int j = i - 1;
            while(j && A[j - 1] == A[j]) j--;

            if((i - j) % 2 || (A[i] - N - i) % 2) {
                printf("First");
                return 0;
            }
            else {
                printf("Second");
                return 0;
            }
        }
        else if(i == 0 || A[i - 1] < N - i) {
            if((A[i] - N + i) % 2) {
                printf("First");
                return 0;
            }
            else {
                printf("Second");
                return 0;
            }
        }
    }
}
