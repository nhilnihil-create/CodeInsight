#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int N, M;
ll K;
ll X[100010], D[100010];
int A[100010], P[100010], R[100010], T[100010];

void solve(ll k) {
    if(k == 1) {
        for(int i = 0; i < N - 1; i++) R[i] = P[i];
        return;
    }
    solve(k / 2);

    for(int i = 0; i < N - 1; i++) T[i] = R[ R[i] ];
    for(int i = 0; i < N - 1; i++) R[i] = T[i];

    if(k % 2) {
        for(int i = 0; i < N - 1; i++) T[i] = R[ P[i] ];
        for(int i = 0; i < N - 1; i++) R[i] = T[i];
    }
}

int main() {
    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        scanf("%lld", &X[i]);
    }
    for(int i = 0; i < N - 1; i++) {
        D[i] = X[i + 1] - X[i];
    }

    scanf("%d %lld", &M, &K);

    for(int i = 0; i < M; i++) {
        scanf("%d", &A[i]);
        A[i]--;
    }
    for(int i = 0; i < N - 1; i++) P[i] = i;
    for(int i = 0; i < M; i++) {
        swap(P[ A[i] - 1 ], P[ A[i] ]);
    }

    solve(K);

    printf("%lld\n", X[0]);
    ll prev = X[0];
    for(int i = 1; i < N; i++) {
        printf("%lld\n", prev + D[ R[i - 1] ]);
        prev += D[ R[i - 1] ];
    }
}
