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
  ll res=0,res1=INF,res2=-INF,buf=0,buf1=0,buf2=0,buf3=0,buf4=0,sum=0;
  bool judge = true;
  ll n,a,b,c,d;cin>>n>>a>>b>>c>>d;
  ll t=c+d;
  n--;
  if(n%2==0){
    buf=(abs(b-a))%t;
    ans2((buf<=(d-c)*(n/2)||buf>=t-(d-c)*(n/2))&&abs(b-a)<=n*d);
    //cout<<buf spa (d-c)*(n/2) spa t-(d-c)*(n/2)<<endl;
  }
  else{
    buf=abs(b-a)%t;
    if(buf>=(t+1)/2)buf-=(t+1)/2-1;
    else buf=(t+1)/2-buf;
    ans2((buf<=((d-c)*n+1)/2)&&abs(b-a)<=n*d);
    //cout<<buf spa ((d-c)*n+1)/2<<endl;
  }
  return 0;
}