#pragma GCC optimize("Ofast")
#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
typedef pair<ll,ll> P;
typedef pair<P,long double> Pi;
typedef pair <long double,int> Pd;
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
const ll inf=(1e18);
const ll mod=1000000007;
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
struct data{
  ll a,b,c;
};
ll dp[41][405][405];
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
ll n,ma,mb;
cin>>n>>ma>>mb;
vector<data> d(n);
for(int i=0;i<n;i++){
  cin>>d[i].a>>d[i].b>>d[i].c;
}
for(int i=0;i<=n;i++){
  for(int j=0;j<401;j++){
    for(int k=0;k<401;k++){
      dp[i][j][k]=inf;
    }
  }
}
ll ans=inf;
dp[0][0][0]=0;
for(int i=0;i<n;i++){
  for(int j=0;j<401;j++){
    for(int k=0;k<401;k++){
      if(j+d[i].a<=400&&k+d[i].b<=400)chmin(dp[i+1][j+d[i].a][k+d[i].b],dp[i][j][k]+d[i].c);
       chmin(dp[i+1][j][k],dp[i][j][k]);
    }
  }
}
  for(int j=1;j<401;j++){
    for(int k=1;k<401;k++){
     if(j*mb==k*ma)chmin(ans,dp[n][j][k]);
    }
  }
if(ans==inf)cout<<-1<<endl;
else cout<<ans<<endl;
}

