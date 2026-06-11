#include<bits/stdc++.h>
using namespace std;

const int MAX = 100005;
int A[MAX];

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &A[i]);

    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] == i+1) {
            ans++;
            i++;
        }
    }

    printf("%d\n", ans);
    return 0;
}