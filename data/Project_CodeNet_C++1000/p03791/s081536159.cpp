#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
#define fori(i,a,b) for(int i=(a);i<(int)(b);i++)
#define repi(i,n) fori(i,0,n)
#define forr(i,a,b) for(int i=int(b-1);i>=int(a);i--)
#define repr(i,n) forr(i,0,n)
#define all(x) (x).begin(),(x).end()
#define fill(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define mp make_pair
#define pcnt __builtin_popcount
template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return 1;}return 0;}
const ll MOD = 1000000007;

#define MAX 100010
ll x[MAX];
void solve(){
    ll n;cin>>n;
    repi(i,n)cin>>x[i];

    ll ans=1;
    ll cnt=0;
    repi(i,n){
        if(x[i]>2*cnt)cnt++;
        else (ans*=cnt+1)%=MOD;
    }
    repi(i,cnt)(ans*=i+1)%=MOD;
    cout<<ans<<endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
