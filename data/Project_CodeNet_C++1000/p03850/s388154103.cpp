#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MN = 100010;

int N;
int A[MN];
char B[MN];
ll psum[MN];

ll calc(int l, int r) {
    return psum[r] - (l? psum[l - 1] : 0);
}

int main() {
    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        if(i) {
            scanf(" %c", &B[i]);
        }
        scanf("%d", &A[i]);
    }

    for(int i = 0; i < N; i++) {
        psum[i] = A[i];
        if(i) psum[i] += psum[i - 1];
    }

    ll ans = -1e18;
    ll sum = A[0];

    for(int i = 1; i < N; i++) {
        if(B[i] == '-') {
            ll tmp = A[i];
            int j;
            for(j = i + 1; j < N; j++) {
                if(B[j] == '-') break;
                tmp += A[j];
            }

            ans = max(ans, sum - tmp + calc(j, N - 1));
            sum -= A[i];
        }
        else sum += A[i];
    }
    ans = max(ans, sum);
    printf("%lld", ans);
}
