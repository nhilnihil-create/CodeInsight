#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i < (int)(n);i++)
const ll mod = 1e9+7;
int main(){
   ll n,a,b;
   cin >> n >> a >> b;
   priority_queue<ll> pq;
   int tmp;
   int now;
   ll ans=0;
   cin >> tmp;
   for(int i=1;i < n;i++){
     cin >> now;
     ans+=min(b,(now-tmp)*a);
     //printf("now-tmp %d\n",now-tmp);
     tmp=now;
     //printf("ans: %lld\n",ans);
   }
   cout << ans << endl;

   

   return 0;
}

