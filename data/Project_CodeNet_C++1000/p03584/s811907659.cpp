#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

int N, K;
vector<pii> P;

int main() {
    scanf("%d %d", &N, &K);
    P.resize(N);
    for(int i = 0; i < N; i++) {
        scanf("%d %d", &P[i].first, &P[i].second);
    }

    ll mx = 0;
    ll cost = 0;
    for(int i = 0; i < N; i++) {
        if((K | P[i].first) == K) cost += P[i].second;
    }
    mx = cost;

    while(1) {
        if(K == 0) break;
        int nK = K - 1;
        ll cost = 0;
        for(int i = 0; i < N; i++) {
            if((nK | P[i].first) == nK) cost += P[i].second;
        }
        mx = max(mx, cost);
        K -= (K & -K);
    }
    printf("%lld", mx);
}
