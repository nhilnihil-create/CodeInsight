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


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n;
  cin >> n;
  VI a(n);
  map<int,int> mp;
  rep(i,n){
    cin >> a[i];
    mp[a[i]]++;
  }
  sort(all(a));

  if(a.back() - a[0] >= 2){
    cout << "No" << "\n";
    return 0;
  }


  // a[0] == mm + cnt1 - 1
  // a[0] + 1 == mm + cnt1;
  if(a[0] == a.back()){
    //もしも全て複数ケース存在する場合
    if( n >= 2*a[0]){
      cout << "Yes" << "\n";
      return 0;
    }

    // もしも全てユニークケース
    if(a[0] == (n -1) ){
      cout << "Yes" << "\n";
      return 0;
    }

    cout << "No" << "\n";
  }else{
    // 混在する場合
    ll uniqueCnt = mp[a[0]]; //少ない方の個数
    ll amari = (a[0] - uniqueCnt) + 1;
    // cout << amari << " " << uniqueCnt << endl;
    if(amari <= 0) {
      cout << "No" << "\n";
      return 0;
    }

    if(amari*2 <= mp[a[0]+1] && amari + uniqueCnt == (a[0]+1) ){
      cout << "Yes" << "\n";
      return 0;
    }
    cout << "No" << "\n";

  }

  return 0;
}
