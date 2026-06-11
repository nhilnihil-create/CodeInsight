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
    cin>>N>>M;
    vec x(N);
    rep(i,N) cin>>x[i];
    vec num(M,0);
    mat same(M, vec(0));
    sort(ALL(x));
    ll last = 0, temp = 0;
    rep(i,N){
        ++num[x[i]%M];
        if(x[i] == last) {
            temp = (temp == 0 ? 2 : temp + 1);
        }else{
            if(temp != 0) same[x[i-1]%M].push_back(temp);
            temp = 0;
        }
        last = x[i];
    }
    if(temp != 0) same[x[N-1]%M].push_back(temp);
    ll ans = 0;
    rep(i,M/2 + 1){
        ll I = i, J = (M - i)%M;
        if(I != J) {
            if (num[I] < num[J]) swap(I, J);
            ll sa = 0;
            for(ll a : same[I]) sa += a/2;
            ans += num[J] + min(sa, (num[I] - num[J])/2);
        }else{
            ans += num[I]/2;
        }
        //cout<<I<<' '<<num[I]<<endl;
    }
    cout<<ans<<endl;
}