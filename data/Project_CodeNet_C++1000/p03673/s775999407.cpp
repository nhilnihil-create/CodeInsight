#include <bits/stdc++.h>

#define rep(i, N) for (ll i = 0; i < N; i++)
#define rep1(i, N) for (ll i = 1; i <= N; i++)
#define repr(i, N) for (ll i = N-1; i >= 0; i--)
#define repr1(i, N) for (ll i = N; i > 0; i--)

#define MOD 1000000007

using ll = long long;
using namespace std;

typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<P> vpi;


int main() {
    ll n,ans = 0,num = 0;
    cin >> n;
    vi a(n);
    rep(i,n) cin >> a[i];

    if(n%2 == 0) {
        repr(i,n/2) cout << a[i*2+1] << " ";
        rep(i,n/2) cout << a[i*2] << " ";
    } else {
        repr(i,n/2+1) cout << a[i*2] << " ";
        rep(i,n/2) cout << a[i*2+1] << " ";
    }
    
    //printf("%.15lf", ans);
    cout << "\n";
    return 0;
}
