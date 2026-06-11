#include <bits/stdc++.h>
using namespace std;

//repetition
#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

//container util
#define all(x) (x).begin(),(x).end()

//typedef
typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

//const value
//const ll MOD = 1e9 + 7;
//const int dx[] = {0,1,0,-1};//{0,0,1,1,1,-1,-1,-1};
//const int dy[] = {1,0,-1,0};//{1,-1,0,1,-1,0,1,-1};

//conversion
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
inline ll toLL(string s) {ll v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
int n,m;
int ans = INT_MAX;
int sum[301];
VVI a;

void dfs(vector<bool> &ng){

  memset(sum,0,sizeof(sum));

  rep(i,n){
    int minIdx = INT_MAX;
    int addIdx = m;

    rep(j,m){
      if(ng[j]) continue;
      if(minIdx > a[i][j] ){
        minIdx = a[i][j];
        addIdx = j;
      }
    }
    sum[addIdx]++;
  }

  if(sum[m] > 0) return;
  int maxNum = -1;
  rep(i,m) maxNum = max(sum[i],maxNum);
  // rep(i,m){
  //   if(maxNum == 2){
  //     if(ng[i]) cout << "- ";
  //     else cout << sum[i] << " ";
  //
  //     if(maxNum == 2 && i == m-1) cout << endl;
  //   }
  // }
  ans = min(ans, maxNum);

  rep(i,m){
    if(maxNum == sum[i]){
      ng[i] = true;
      dfs(ng);
      ng[i] = false;
    }
  }

}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;
  a.resize(n,VI(m));

  rep(i,n) rep(j,m){
    int tmp;
    cin >> tmp;
    a[i][tmp-1] = j;
  }
  vector<bool> ng(m+1,false);
  dfs(ng);

  cout << ans << endl;
  return 0;
}
