#include<bits/stdc++.h>
using namespace std;

#define ld long double
#define ll long long
#define ALL(a)  (a).begin(),(a).end()
#define ALLR(a)  (a).rbegin(),(a).rend()
#define spa << " " <<
#define MP make_pair
ll MOD = 1e9+7;
//ll MOD = 998244353;
ll INF = 1e18;
void chmin(ll &a,ll b){if(a>b)a=b;}
void chmax(ll &a,ll b){if(a<b)a=b;}
void pmod(ll &a,ll b){a=(a+b)%MOD;}
void qmod(ll &a,ll b){a=(a*b)%MOD;}
void ans1(bool x){if(x) cout<<"Yes"<<endl;else cout<<"No"<<endl;}
void ans2(bool x){if(x) cout<<"YES"<<endl;else cout<<"NO"<<endl;}
void ans3(bool x){if(x) cout<<"Yay!"<<endl;else cout<<":("<<endl;}
void ans(bool x,ll y,ll z){if(x)cout<<y<<endl;else cout<<z<<endl;}
void anss(bool x,string y,string z){if(x)cout<<y<<endl;else cout<<z<<endl;}   
ll gcd(ll x,ll y){ll r;while((r=x%y)!=0){x=y;y=r;}return y;}

int main(){
  ll i,j,o;
  ll res=0,res1=0,res2=INF,buf=0,buf1=0,buf2=0,buf3=0,buf4=0;
  bool judge = true;
  ll n;cin>>n;
  ll psum=0,qsum=0;
  vector<ll> a(3*n);
  priority_queue<ll,vector<ll>,greater<ll>> p;
  priority_queue<ll> q;
  vector<ll> b(n+1),c(n+1);
  for(i=0;i<3*n;i++){
    cin>>a[i];
    if(i<n){
      psum+=a[i];
      p.push(a[i]);
    }
    else if(i>=2*n){
      qsum+=a[i];
      q.push(a[i]);
    }
  }
  b[0]=psum;c[0]=qsum;
  for(i=n;i<2*n;i++){
    if(p.top()<a[i]){
      //cout<<p.top() spa a[i]<<endl;
      psum+=a[i]-p.top();
      p.pop();
      p.push(a[i]);
    }
    b[i-n+1]=psum;
    //cout<<b[i-n+1] spa i-n+1<<endl;

  }
  for(i=n;i<2*n;i++){
    if(q.top()>a[3*n-i-1]){
      qsum+=a[3*n-i-1]-q.top();
      q.pop();
      q.push(a[3*n-i-1]);
    }
    c[i-n+1]=qsum;
  }
  res=-INF;
  for(i=0;i<n+1;i++){
    chmax(res,b[i]-c[n-i]);
    //cout<<b[i] spa c[n-i]<<endl;
  }
  cout<<res<<endl;
  return 0;
}