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
const ll zero=0;
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

int main(){
  ll i,j,o;
  ll res=0,res1=INF,res2=-INF,buf=0;
  bool judge = true;
  ll n;cin>>n;
  vector<ll>a(n);
  for(i=0;i<n;i++)cin>>a[i];
  ll sumbuf=0;
  vector<ll>b(n);
  for(i=0;i<n;i++){
    sumbuf+=a[i];
  }
  b[0]=a[0]-a[n-1];
  for(i=1;i<n;i++)b[i]=a[i]-a[i-1];
  if(sumbuf%(n*(n+1)/2)!=0)judge=false;
  else{
    ll numbuf=sumbuf/((n*(n+1))/2);
    ll countbuf=0;
    //cout<<sumbuf spa numbuf<<endl;
    for(i=0;i<n;i++){
      //cout<<numbuf-b[i] spa b[i]<<endl;
      if((numbuf-b[i])<-1||(numbuf-b[i])%n!=0){
        judge=false;break;
      }
      else{
        countbuf+=(numbuf-b[i])/n;
      }
    }
    if(countbuf!=numbuf)judge=false;
  }
  ans2(judge);
  return 0;
}