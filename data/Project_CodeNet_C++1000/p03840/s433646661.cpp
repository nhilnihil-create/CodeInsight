#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
#define Rreps(i,n,e) for(int i = n - 1; i >= e; --i)
#define Rrep(i,n) Rreps(i,n,0)
#define ALL(a) a.begin(), a.end()
#define fi first
#define se second
#define mp make_pair
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

ll N,M,H,W,K,Q,A,B,L,R;
string S, T;
const ll MOD = 998244353;
const ll INF = 1LL << 60;
typedef pair<ll,ll> P;

typedef vector<P> vp;
typedef vector<vp> matP;

int main() {
    vec a(3);
    ll ans;
    cin>>a[0]>>ans>>A>>a[1]>>a[2]>>A>>A;
    ll temp = 0;
    rep(i,3) temp += a[i]/2;
    temp *= 2;
    rep(i,3){
        if(a[i] == 0){
            cout<<ans + temp<<endl;
            return 0;
        }
    }
    ll t = 3;
    rep(i,3) t += ((a[i] - 1)/2)*2;
    cout<<max(ans + temp, ans + t)<<endl;
}