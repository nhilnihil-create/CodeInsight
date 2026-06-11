#include<bits/stdc++.h>
using namespace std;

#define ALL(a)  (a).begin(),(a).end()
#define ALLR(a)  (a).rbegin(),(a).rend()
#define spa << " " <<
#define MP make_pair
#define test cout<<"test"<<endl;
#define fi first
#define se second
typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const ll INF = 1e18;
using P = pair<ll, ll>;
void chmin(ll &a,ll b){if(a>b)a=b;}
void chmax(ll &a,ll b){if(a<b)a=b;}
void pmod(ll &a,ll b){a=(a+b)%MOD;}
void pmod(ll &a,ll b,ll c){a=(b+c)%MOD;}
void qmod(ll &a,ll b){a=(a*b)%MOD;}
void qmod(ll &a,ll b,ll c){a=(b*c)%MOD;}
void ans1(bool x){if(x) cout<<"Yes"<<endl;else cout<<"No"<<endl;}
void ans2(bool x){if(x) cout<<"YES"<<endl;else cout<<"NO"<<endl;}
void ans3(bool x){if(x) cout<<"Yay!"<<endl;else cout<<":("<<endl;}
void ans(bool x,ll y,ll z){if(x)cout<<y<<endl;else cout<<z<<endl;}
void ans(bool x,string y,string z){if(x)cout<<y<<endl;else cout<<z<<endl;}   
ll gcd(ll x,ll y){ll r;while((r=x%y)!=0){x=y;y=r;}return y;}
//m.emplace(x,0).fi->second++;

int main(){
  ll i,j,o;
  ll res=0,res1=INF,res2=-INF,buf=0;
  bool judge = true;
  ll n,x;cin>>n>>x;
  if(n==2){
    if(x==2)cout<<"Yes\n1\n2\n3"<<endl;
    else cout<<"No"<<endl;
  }
  else{
    if(x==1||x==2*n-1)cout<<"No"<<endl;
    else{
      cout<<"Yes"<<endl;
      if(x<=n){
        for(i=2;i<=n-1;i++){
          if(i!=x)cout<<i<<endl;
        }
        cout<<2*n-1<<endl;
        cout<<x<<endl;
        cout<<1<<endl;
        cout<<2*n-2<<endl;
        for(i=n;i<=2*n-3;i++){
          if(i!=x)cout<<i<<endl;
        }
      }
      else{
        for(i=3;i<=n-1;i++){
          if(i!=x)cout<<i<<endl;
        }
        cout<<1<<endl;
        cout<<x<<endl;
        cout<<2*n-1<<endl;
        cout<<2<<endl;
        for(i=n;i<=2*n-2;i++){
          if(i!=x)cout<<i<<endl;
        }
      }
    }
  }

  return 0;
}