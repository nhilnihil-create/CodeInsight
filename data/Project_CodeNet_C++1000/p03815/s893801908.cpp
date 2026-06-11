#include <bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep2(i,m,n) for(int (i)=(m);(i)<(n);(i)++)
#define ll long long
#define ld long double
#define all(a) (a).begin(),(a).end()
#define mk make_pair
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;
ll MOD=1000000007;
int main(){
  ll x;
  cin>>x;
  ll module=x/11;
  ll remainder=x%11;
  if(remainder==0) cout<<2*module<<endl;
 else if(remainder<=6) cout<<2*module+1<<endl;
 else cout<<2*module+2<<endl;
return 0;
}