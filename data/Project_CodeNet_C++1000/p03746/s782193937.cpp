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

vector<vector<ll>> a(100001);//隣接リスト(添え字は始点、値は終点)
vector<ll>t(100001);//訪問したかどうか
vector<ll>ret1;
vector<ll>ret2;
void dfs1(ll k, ll f){
  t[k]=1;
  ret1.push_back(k+1);
  for(ll i=0;i<a[k].size();i++){
    if(t[a[k][i]]==0){
      dfs1(a[k][i],k); 
      return;
    }
  }
}
void dfs2(ll k, ll f){
  t[k]=1;
  ret2.push_back(k+1);
  for(ll i=0;i<a[k].size();i++){
    if(t[a[k][i]]==0){
      dfs2(a[k][i],k); 
      return;
    }
  }
}


int main(){
  ll i,j,o;
  ll res=0,res1=INF,res2=-INF,buf=0;
  bool judge = true;
  ll n,m;cin>>n>>m;
  for(i=0;i<m;i++){
    ll p,q;
    cin>>p>>q;
    a[p-1].push_back(q-1);
    a[q-1].push_back(p-1);
  }
  dfs1(0,-1);
  dfs2(0,-1);
  cout<<ret1.size()+ret2.size()-1<<endl;
  reverse(ALL(ret2));
  for(i=0;i<ret2.size()-1;i++)cout<<ret2[i]<<" ";
  for(i=0;i<ret1.size();i++)cout<<ret1[i]<<" ";
  cout<<endl;


  return 0;
}