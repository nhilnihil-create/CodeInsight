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
string S, T;
const ll MOD = (1e+9) + 7;
const ll INF = 1LL << 60;
typedef pair<ll,ll> P;

typedef vector<P> vp;
typedef vector<vp> matP;

int main() {
    cin>>N;
    vec a(N);
    rep(i,N) cin>>a[i];
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    ll last = a[0], count = 1;
    S = "Possible";
    reps(i,1,N){
        if(count < 2 && last != a[i]) S = "Impossible";
        if(abs(last - a[i]) > 1) S = "Impossible";
        if(last != a[i]){
            last = a[i];
            count = 1;
        }else{
            ++count;
        }
    }
    if(a[0]%2){
        if(last != (a[0]+1)/2 || count != 2) S = "Impossible";
    }else{
        if(last != a[0]/2 || count != 1) S = "Impossible";
    }
    cout<<S<<endl;
}