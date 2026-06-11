#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1010000000000000017LL;
const ll MOD = 1000000007LL;

#define REP(i, n) for(ll i = 0 ; i < n; i++)

#ifdef DEBUG
#define DBG(fmt, ...) fprintf(stderr, fmt "\n", ##__VA_ARGS__)
#else
#define DBG(fmt, ...)
#endif

int main(){
    std::cout<<std::fixed<<std::setprecision(10);

    ll N, K;
    cin >> N >> K;
    vector<ll> a(N);
    REP(i,N){ cin >> a[i]; }

    ll ans = INF;
    for(int s = 0; s < (1 << (N)); s++){
        if( ! ((s & 1) && (__builtin_popcount(s) == K)) ){
            continue;
        }

        ll height = 0;
        ll cost = 0;
        for(int i = 0; i < N; i++ ){
            if( s & (1<<i) ){
                if( a[i] <= height ){
                    height = height+1;
                    cost += height - a[i];
                }else{
                    height = a[i];
                }
            }else{
                if( a[i] > height ){
                    height = a[i];
                }
            }
        }


        ans = min(ans, cost);
    }

    cout << ans << endl;
}
