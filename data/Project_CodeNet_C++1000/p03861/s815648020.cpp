#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define all(v) v.begin(), v.end()
#define F first
#define S second
#define INF 1000000000000
#define MOD 10000007
typedef long long ll;
//
int main(){
   ll a,b,x;cin>>a>>b>>x;
   ll ans=0;
   if(a==0){
      ans++;
      a++;
   }
    ans+=b/x-(a-1)/x;

   cout<<ans<<endl;
}