#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int N;
int X[555], A[555 * 555];
vector<pii> P;

int main() {
    scanf("%d", &N);

    for(int i = 1; i <= N; i++) {
        scanf("%d", &X[i]);
        P.push_back({ X[i], i });
    }
    sort(P.begin(), P.end());

    int sum = 0;
    for(int i = 0; i < N; i++) {
        sum += P[i].second - 1;
        if(P[i].first - 1 < sum) {
            printf("No");
            return 0;
        }
        sum++;
    }

    sum = 0;
    for(int i = N - 1; i >= 0; i--) {
        sum += N - P[i].second;
        if(N * N - P[i].first < sum) {
            printf("No");
            return 0;
        }
        sum++;
    }

    printf("Yes\n");

    for(int i = 1; i <= N; i++) {
        A[ X[i] ] = i;
    }
    int pos = 1;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < P[i].second - 1; j++) {
            while(A[pos]) pos++;
            A[pos] = P[i].second;
        }
    }
    pos = N * N;
    for(int i = N - 1; i >= 0; i--) {
        for(int j = 0; j < N - P[i].second; j++) {
            while(A[pos]) pos--;
            A[pos] = P[i].second;
        }
    }

    for(int i = 1; i <= N * N; i++) {
        printf("%d ", A[i]);
    }
}
