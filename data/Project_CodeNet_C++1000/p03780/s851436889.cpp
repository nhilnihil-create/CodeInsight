#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<ll, ll, ll> T;

int N, K;
vector<ll> a(5001, 0);

int main(void){
    
    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; ++i) scanf("%lld", &a[i]);
    sort(a.begin(), a.begin() + N);
    
    int ans = N;
    ll sum = 0;
    for(int i = N - 1; i >= 0; --i){
        if((sum + a[i]) < K) sum += a[i];
        else ans = min(ans, i);
    }
    printf("%d\n", ans);
    
    return 0;
}