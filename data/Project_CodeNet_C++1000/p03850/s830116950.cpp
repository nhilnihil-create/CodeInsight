#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int N;
vector<int> A;
vector<char> O;
vector<ll> psum;
vector<int> sidx;
vector<ll> res;

int main() {
    scanf("%d", &N);
    A.resize(N);
    O.resize(N - 1);
    for(int i = 0; i < N - 1; i++) {
        scanf("%d %c", &A[i], &O[i]);
    }
    scanf("%d", &A[N - 1]);

    psum.resize(N);
    for(int i = 0; i < N; i++) {
        psum[i] = A[i];
        if(i) psum[i] += psum[i - 1];
    }

    for(int i = 0; i < N - 1; i++) {
        if(O[i] == '-') sidx.push_back(i);
    }

    ll ans = A[0];
    res.resize(N);
    res[0] = ans;

    for(int i = 1; i < N; i++) {
        ans += O[i - 1] == '+'? A[i] : -A[i];
        res[i] = ans;
    }

    sidx.push_back(N - 1);

    for(int i = 0; i < (int)sidx.size() - 1; i++) {
        int now = sidx[i];
        int nxt = sidx[i + 1];

        ans = max(ans, res[now] + -(psum[nxt] - psum[now]) + psum[N - 1] - psum[nxt]);
    }

    printf("%lld", ans);
}
