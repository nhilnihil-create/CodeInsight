#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define PI 3.14159265359
#define INF 1000100100//000000000
#define MOD 1000000007
#define all(x) (x).begin(),(x).end()
typedef long long ll;
#define P pair<int, int>
#define PP pair<P,P>
#define T tuple<int,int,int> //tuple<ll,ll,ll>
#define pr(x) cout << x << endl;
using namespace std;

int main(){
  int n; cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  ll ans=0;
  ll sum=0;
  rep(i,n){
    sum+=a[i];
    if(i%2==0 && sum<=0){
      ans+=-sum+1;
      sum=1;
    }
    if(i%2==1 && sum>=0){
      ans+=sum+1;
      sum=-1;
    }
  }
  ll ans2=0;
  sum=0;
  rep(i,n){
    sum+=a[i];
    if(i%2==1 && sum<=0){
      ans2+=-sum+1;
      sum=1;
    }
    if(i%2==0 && sum>=0){
      ans2+=sum+1;
      sum=-1;
    }
  }
  cout << min(ans,ans2) << endl;
return 0;
}
