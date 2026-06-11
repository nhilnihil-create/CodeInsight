#include<bits/stdc++.h>
using namespace std;

const int MN = 100010;

int gcd(int a, int b) {
    return b? gcd(b, a % b) : a;
}

int N;
int A[MN];

int main() {
    scanf("%d", &N);

    int sum = 0;
    for(int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
        sum ^= (A[i] - 1) & 1;
    }

    if(sum % 2) {
        printf("First");
        return 0;
    }
    if(N == 1) {
        printf("Second");
        return 0;
    }

    int turn = 1;
    while(1) {
        int cnt = 0;
        for(int i = 0; i < N; i++) {
            if(A[i] % 2) cnt++;
        }
        if(cnt > 1) {
            if(turn) printf("Second");
            else printf("First");
            return 0;
        }
        int g = 0;
        for(int i = 0; i < N; i++) {
            if(A[i] % 2) A[i]--;
            g = gcd(g, A[i]);
        }
        sum = 0;
        for(int i = 0; i < N; i++) {
            A[i] /= g;
            if(A[i] == 0) {
                sum = 1;
                break;
            }
            sum ^= (A[i] - 1) & 1;
        }
        if(sum % 2) {
            if(turn) printf("Second");
            else printf("First");
            return 0;
        }

        turn ^= 1;
    }
}
