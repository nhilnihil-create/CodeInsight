#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define srep(i,s,t) for(int i = s; i < t; ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
#define yn {puts("Yes");}else{puts("No");}
#define MAX_N 200005

int main() {
    int n, k;
    cin >> n >> k;

    ll a[n] = {};
    rep(i,n) cin >> a[i];

    ll ans = 1001001001001001001;

    rep(i,1<<n){
        bitset<20> f(i);
        if(__builtin_popcount(i) != k) continue;
        ll tmp = 0;
        int now = 0;
        rep(j,n){
            if(a[j] > now){
                now = a[j];
            }else{
                if(f[j] == 0) continue;
                tmp += now + 1 - a[j];
                now = now + 1;
            }
        }
        ans = min(ans, tmp);
    }
    
    cout << ans << endl;
    return 0;
}


