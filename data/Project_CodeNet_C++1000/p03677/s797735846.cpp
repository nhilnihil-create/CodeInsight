#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
#define fi first
#define se second
#define mp make_pair
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

ll N,M,H,W,K,Q,A,B,L,R;
string S,T;
const ll MOD = (1e+9) + 7;
const ll INF = 1LL << 60;
typedef pair<ll,ll> P;

typedef vector<P> vp;
typedef vector<vp> matP;

int main() {
    cin>>N>>M;
    vec a(N);
    rep(i,N) {
        cin>>a[i];
        --a[i];
    }
    vec num(M*2,0), minus_num(M*2,0), switch_erase(M*2,0);
    ll sum = 0;
    reps(i,1,N){
        ll last = a[i-1], next = a[i];
        if(next < last) next += M;
        sum += next - last;
        ++num[last]; --minus_num[next];
        switch_erase[next] += next - last - 1;
    }
    ll stock = 0, adv = 0;
    vec memo(M,0);
    rep(i,M*2){
        if(i != 0) adv += stock - num[i-1];
        memo[i%M] += adv;
        stock += num[i] + minus_num[i];
        adv -= switch_erase[i];
    }
    ll ans = sum;
    rep(i,M) ans = min(ans, sum - memo[i]);
    /*rep(i,M){
        if(sum - memo[i] == ans) cout<<i<<endl;
    }*/
    cout<<ans<<endl;
}