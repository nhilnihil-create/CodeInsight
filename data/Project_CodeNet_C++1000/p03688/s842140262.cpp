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

int main() {
    cin>>N;
    vec a(N);
    ll ma = 0, mi = N;
    rep(i,N){
        cin>>a[i];
        ma = max(ma, a[i]);
        mi = min(mi, a[i]);
    }
    S = "Yes";
    if(ma - mi >= 2) {
        S = "No";
    }else if(ma - mi == 1){
        ll kind = ma, num = N;
        rep(i,N){
            if(a[i] == mi){
                --num; --kind;
            }
        }
        if(kind <= 0 || kind*2 > num) S = "No";
    }else {
        if(ma != N - 1 && ma * 2 > N) S = "No";
    }
    cout<<S<<endl;
}