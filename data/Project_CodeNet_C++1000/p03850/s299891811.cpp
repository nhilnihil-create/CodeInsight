#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+100;
#define fr(i,a,b) for(int i = a;i <= b; ++i)
#define nfr(i,a,b) for(int i = a;i >= b; --i)
#define pb push_back

int n,a[N];
char sgn[N];
ll f[N][2];
ll ans;
ll ssum[N];
/*
5
1 - 20 - 13 + 14 - 5
*/

int main(){
   ios::sync_with_stdio(false);
   ans = -0x3f3f3f3f;
   cin >> n;
   fr(i,1,n){
      if(i > 1)cin >> sgn[i]; cin >> a[i];
      if(sgn[i] == '-')a[i] = -a[i];
   }

   ssum[n+1] = 0;
   nfr(i,n,1)ssum[i] = ssum[i+1]+abs(a[i]);

   memset(f,0xf7,sizeof f);
   f[0][0] = 0;
   fr(i,1,n){
      f[i][0] = max(f[i-1][0]+a[i],f[i-1][1]+a[i]);
      f[i][1] = f[i-1][1]-a[i];
      if(sgn[i] == '-')f[i][1] = max(f[i][1],f[i-1][0]+a[i]);
      if(sgn[i] == '-' )ans = max(ans,f[i-1][1]+ssum[i]);
   }
   ans = max(ans,max(f[n][0],f[n][1]));
   printf("%lld\n",ans);
   return 0;
}
