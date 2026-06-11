#include<bits/stdc++.h>
using namespace std;

#define ld long double
#define ll long long
#define ALL(a)  (a).begin(),(a).end()
#define ALLR(a)  (a).rbegin(),(a).rend()
#define spa << " " <<
#define MP make_pair
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
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
  ll res=0,res1=0,res2=INF,buf=0,buf1=0,buf2=0,buf3=0,buf4=0,sum=0;
  ll l,r;
  bool judge = true;
  ll n,k;
  cin>>n>>k;
  vector<ll> a;
  a.push_back(0);
  for(i=0;i<n;i++){
    cin>>buf;
    if(buf<k){
      a.push_back(buf);
      res+=buf;
    }
  }
  sort(ALL(a));
  l=0;r=a.size()-1;
  while(abs(l-r)>1){
    buf=(l+r)/2;
    //cout<<l spa r spa buf<<endl;
    vector<bool> dp(k,false);
    dp[0]=true;
    for(i=0;i<a.size();i++){
      if(buf!=i){
        for(j=k-1;j>=0;j--){
          if(dp[j]&&j+a[i]<k)dp[j+a[i]]=true;
        }
      }
    }
    judge=false;
    for(i=k-1;i>=0;i--){
      if(dp[i]&&i+a[buf]>=k){
        judge=true;
        break;
      }
    }
    if(judge)r=buf;
    else l=buf;
    //cout<<l spa r spa buf<<endl;
  }
  if(res<k)l=r;
  cout<<l<<endl;
  return 0;
}