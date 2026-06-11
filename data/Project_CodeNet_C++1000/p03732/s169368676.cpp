/*
        _            _                  _            _       _     _         _   _          _          _             _        
       / /\         / /\               / /\         / /\    / /\  /\ \      /\_\/\_\ _     /\ \       /\ \     _    /\ \      
      / /  \       / /  \             / /  \       / / /   / / /  \ \ \    / / / / //\_\   \ \ \     /  \ \   /\_\ /  \ \     
     / / /\ \__   / / /\ \           / / /\ \__   / /_/   / / /   /\ \_\  /\ \/ \ \/ / /   /\ \_\   / /\ \ \_/ / // /\ \_\    
    / / /\ \___\ / / /\ \ \         / / /\ \___\ / /\ \__/ / /   / /\/_/ /  \____\__/ /   / /\/_/  / / /\ \___/ // / /\/_/    
    \ \ \ \/___// / /  \ \ \        \ \ \ \/___// /\ \___\/ /   / / /   / /\/________/   / / /    / / /  \/____// / / ______  
     \ \ \     / / /___/ /\ \        \ \ \     / / /\/___/ /   / / /   / / /\/_// / /   / / /    / / /    / / // / / /\_____\ 
 _    \ \ \   / / /_____/ /\ \   _    \ \ \   / / /   / / /   / / /   / / /    / / /   / / /    / / /    / / // / /  \/____ / 
/_/\__/ / /  / /_________/\ \ \ /_/\__/ / /  / / /   / / /___/ / /__ / / /    / / /___/ / /__  / / /    / / // / /_____/ / /  
\ \/___/ /  / / /_       __\ \_\\ \/___/ /  / / /   / / //\__\/_/___\\/_/    / / //\__\/_/___\/ / /    / / // / /______\/ /   
 \_____\/   \_\___\     /____/_/ \_____\/   \/_/    \/_/ \/_________/        \/_/ \/_________/\/_/     \/_/ \/___________/    
                                                                                                                              
*/
#include<bits/stdc++.h>
using namespace std;
#define ALL(obj) (obj).begin(), (obj).end()
#define REP(i, n) for(int i = 0;i < (n);++i)

#define endl '\n'
#define pb emplace_back
#define mkp make_pair
#define p_q priority_queue
#define INF 1000000000
#define PI 3.1415926
#define coutdb cout << fixed << setprecision(10)

const int dx[]={1,0,-1,0}, dy[]={0,-1,0,1};
const int dx_8[]={1,1,0,-1,-1,-1,0,1}, dy_8[]={0,-1,-1,-1,0,1,1,1};
const long long MOD = 1e9+7;

// typedef long long ll;
#define int long long

template <typename T> inline T GCD(T a,T b){T c;while(b!=0){c=a%b;a=b;b=c;}return a;}
template <typename T> inline T LCM(T a,T b){T c=GCD(a,b);a/=c;return a*b;}
template <typename T> inline T nCr(T a,T b){T i,r=1;for(i=1;i<=b;i++){r*=(a+1-i);r/=i;}return r;}
template <typename T> inline T nHr(T a,T b){return nCr(a+b-1,b);}

typedef pair<int, int> P;

signed main(void){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, W, w, v; cin >> N >> W;
  vector<int> vec[4];
  int tmp;
  REP(i, N) {
    cin >> w >> v;
    if(i == 0) tmp = w;
    vec[w-tmp].pb(v);
  }
  REP(i, 4) {
    sort(ALL(vec[i])); reverse(ALL(vec[i]));
  }

  int ans = -1;
  for(int i = 0; i <= (int)vec[0].size(); ++i){
    for(int j = 0; j <= (int)vec[1].size(); ++j){
      for(int k = 0; k <= (int)vec[2].size(); ++k){
        for(int l = 0; l <= (int)vec[3].size(); ++l){
          int wei = tmp*i + (tmp+1)*j + (tmp+2)*k + (tmp+3)*l;
          if(wei > W) continue;
          int sum = 0;
          REP(idx, i) sum += vec[0][idx];
          REP(idx, j) sum += vec[1][idx];
          REP(idx, k) sum += vec[2][idx];
          REP(idx, l) sum += vec[3][idx];
          ans = max(ans, sum);
        }
      }
    }
  }

  cout << ans << endl;
  return 0;
}