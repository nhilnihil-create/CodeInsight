//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main(){
    ll n,p,o=0,e=0,ans=1; cin>>n>>p;
    rep(i,n){
        ll a; cin>>a;
        if(a%2) o++;
        else e++;
    }
    rep(i,n-1) ans*=2;
    if(o==0){
        if(p==1) ans=0;
        else ans*=2;
    }

    cout<<ans<<endl;
}