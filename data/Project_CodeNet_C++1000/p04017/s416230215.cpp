#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
typedef pair<int,int> P;
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
const ll inf=(1e18);
const ll mod=1000000007;
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
   int n;cin>>n;
   vector<ll> a(n);
   for(int i=0;i<n;i++)cin>>a[i];
   int m;cin>>m;
   vector<vector<ll>> dp(100,vector<ll>(n,-1));
   for(int i=0;i<n;i++){
       ll tmp=a[i]+m;
       int ite=upper_bound(all(a),tmp)-a.begin();
       ite--;
       dp[0][i]=ite;
   }
   for(int i=0;i<99;i++){
       for(int j=0;j<n;j++){
           dp[i+1][j]=dp[i][dp[i][j]];
       }
   }
  int q;
  cin>>q;
  while(q--){
      int a,b;
      cin>>a>>b;
      a--;b--;
      if(a>b)swap(a,b);
      int l=-1,r=200000;
      while(r-l!=1){
          int mid=(l+r)/2;
          int tmp=mid;
          int j=0;
          bool can=false;
          int now=a;
          while(tmp!=0){
             if(tmp&1){
                 now=dp[j][now];
             }
             tmp>>=1;
             j++;
             if(now>=b)can=true;
          }
          if(can)r=mid;
          else l=mid;
      }
      cout<<r<<endl;

  }
}


