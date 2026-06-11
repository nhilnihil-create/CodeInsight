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
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

ll N,M,H,W,K,Q,A,B;
string S;
//const ll MOD = 998244353;
const ll MOD = (1e+9) + 7;
const ll INF = 2e+9 + 10;
typedef pair<ll, ll> P;

int main() {
    cin>>N;
    vec num(2e+5, 0);
    rep(i,N){
        cin>>A;
        ++num[A];
    }
    ll ans = 0;
    rep(i, ll(2e+5)) ans += max(0LL, num[i] - 1);
    cout<<N - ((ans + 1) / 2) * 2<<endl;
}