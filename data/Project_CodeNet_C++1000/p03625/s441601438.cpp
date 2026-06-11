#include <bits/stdc++.h>

#define rep(i, N) for (ll i = 0; i < N; i++)
#define rep1(i, N) for (ll i = 1; i <= N; i++)
#define repr(i, N) for (ll i = N-1; i >= 0; i--)
#define repr1(i, N) for (ll i = N; i > 0; i--)

#define MOD 1000000007

using ll = long long;
using namespace std;

typedef pair<ll,ll> P;
typedef vector<ll> vl;
typedef vector<P> vpl;

ll gcd(ll a, ll b){
    if(a < b) swap(a, b);
    if(b <= 0) return -1;
    ll r = a % b;
    while(r != 0){
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

ll lcm(ll a, ll b){
    return (a/gcd(a,b)*b);
}

int main() {
    ll N,W=0,H=0,ans = 0;
    bool flag = false;
    cin >> N;
    vl A(N);
    rep(i,N) cin >> A[i];

    sort(A.begin(), A.end(), greater<ll>());

    rep1(i,N){
        if(A[i] == A[i-1]){
            if(W == 0){
                W = A[i];
                i++;
                continue;
            }else{
                H = A[i];
                ans = H * W;
                break;
            }
        }
    }

    cout << ans;
    //printf("%.15lf", ans);
    cout << "\n";
    return 0;
}
