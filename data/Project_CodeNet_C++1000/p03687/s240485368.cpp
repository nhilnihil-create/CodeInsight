#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> ii;
#define F first
#define S second
#define sqr(x) (x)*(x)
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define rep(i,x,y) for(int i=x;i<(y);++i)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
/* start */

signed main(){
   IOS;
   string s; cin >> s;
   int ans = 110;
   rep(k,0,26){
      int res = 0,n = s.size();
      char c = 'a'+k;
      string t = s;
      while(1){
         vector<int> pos;
         rep(i,0,n){
            if(t[i] == c) pos.pb(i);
         }
         if(pos.size() == n) break;
         for(auto x : pos){
            if(x-1>=0) t[x-1]=c;
         }
         n--;
         res++;
      }
      // cout << t << "\n";
      ans = min(ans,res);
   }
   cout << ans << "\n";
}