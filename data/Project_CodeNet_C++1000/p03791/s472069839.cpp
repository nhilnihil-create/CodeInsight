#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1000*1000*1000+7;
int N;
vector<int> X;

int main() {
    scanf("%d", &N);
    X.resize(N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &X[i]);
    }
    ll ans = 1;
    int cnt = 1;
    for(int i = 0; i < N - 1; i++) {
        if(X[i] >= 2*cnt - 1) cnt++;
        else {
            ans *= cnt;
            ans %= mod;
        }
    }
    for(int i = 1; i <= cnt; i++) {
        ans *= i;
        ans %= mod;
    }
    printf("%lld", ans);
}
