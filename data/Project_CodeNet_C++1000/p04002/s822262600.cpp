#include <bits/stdc++.h>
using namespace std;

//repetition
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

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


//conversion
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

int dx[] = {0,0,0,1,1,1,-1,-1,-1};
int dy[] = {0,1,-1,0,1,-1,0,1,-1};

int main(){
  ll H,W,N;
  cin >> H >> W >> N;
  map<PII, int> cnt;
  rep(i,N){
    int a,b;
    cin >> a >> b;
    a--,b--;
    rep(j,9){
      if(a+dy[j] < H-1 && a+dy[j] >= 1 && b + dx[j] < W-1 && b + dx[j] >= 1){
        //cout << a+dy[j] << " , " <<  b + dx[j] << endl;
        cnt[make_pair(a+dy[j], b + dx[j])]++;
      }
    }
  }

  VLL ans(10,0);
  ll sum = 0;
  for(auto x: cnt){
    //cout << x.first.first << " " <<x.first.second << endl;
    ans[x.second]++;
    sum++;
  }

  ans[0] = (H-2)*(W-2) - sum;
  rep(i,10){
    cout << ans[i] << endl;
  };
  return 0;
}
