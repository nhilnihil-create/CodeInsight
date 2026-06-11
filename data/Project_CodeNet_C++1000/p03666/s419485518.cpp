#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define fi first
#define se second
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define siz(v) (ll)(v).size()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define repn(i,n) for(ll i=0;i<=(ll)(n);i++)
typedef pair<int,int> P;
typedef pair<ll,ll> PL;
const ll mod = 1000000007;
const ll INF = 1000000099;
//cin.tie(0);
//ios::sync_with_stdio(false);
ll n,a,b,c,d;

signed main(){
    cin>>n>>a>>b>>c>>d;
    n--;
    if(b<a)swap(a,b);
    b-=a;

    if(c==d){
     for(int i=0;i <= n;i++)
     {
       if(c*n-i*(c+d) <= b && b <= d*n-i*(c+d)){
         cout<<"YES"<<endl;
         return 0;
       }
     }
     cout<<"NO"<<endl;
     return 0;
    }

    if((n)*(d-c)>=c+d){
      if(b<= d*n)cout<<"YES"<<endl;
      else cout<<"NO"<<endl;
    }else{
     for(int i=0;i <= n;i++)
     {
       if(c*n-i*(c+d) <= b && b <= d*n-i*(c+d)){
         cout<<"YES"<<endl;
         return 0;
       }
     }
     cout<<"NO"<<endl; 
    }
}
