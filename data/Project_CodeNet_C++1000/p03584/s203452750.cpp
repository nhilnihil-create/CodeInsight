#include<iostream>
#include<iomanip>
#include<math.h>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<map>
#include<algorithm>
#include<bitset>
#include<climits>
#include<set>
#include<bitset>
#include<random>
using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define ff first
#define ss second
#define maxs(a,b) a = max(a,b)
#define mins(a,b) a = min(a,b)
#define rep(i,n) for(int i = 0;i < n;i++)


ll n,k;
vector<pair<ll,ll>> a(200020);
int main(void){
   scanf("%lld %lld",&n,&k);
   for(ll i = 0;i < n;i++){
      ll x,y;scanf("%lld %lld",&x,&y);
      a[i] = mp(x,y);
   }
   
   ll ans = 0;
   ll Q = k;
   ll tmp = 0;
   for(ll i = 0;i < n;i++){
      if(Q == (Q | a[i].first)) tmp += a[i].second;
   }
   maxs(ans,tmp);
   for(ll r = 30;r >= 0;r--){
      ll tmp = 0;
      if((k >> r) & 1){
         
         ll Q = 0;
         for(ll i = 31;i > r;i--){
            Q += ((k >> i) & 1) << i;
         }
         for(ll i = r - 1;i >= 0;i--){
            Q += (1 << i);
         }
         
         for(ll i = 0;i < n;i++){
            if(Q == (Q | a[i].first)) tmp += a[i].second;
         }
         maxs(ans,tmp);
      }
   }
   
   
   printf("%lld\n",ans);
   return 0;
}