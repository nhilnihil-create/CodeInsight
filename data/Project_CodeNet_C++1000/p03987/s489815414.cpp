#include <bits/stdc++.h> //C++の標準ライブラリを一行で一括でインクルードする
#include <math.h> //数学関数と数学定数を利用する
#define rep(i,n) for (int i = 0; i < (n); i++)
#define PI 3.141592653589793
using namespace std;
typedef long long ll;
template<class T> void chmax(T &a,T b) { if (a<b) a=b;}
template<class T> void chmin(T &a,T b) { if (a>b) a=b;}
int gcd(int a, int b){//ユークリッドの互除法
  if (a < b) gcd(b,a); //aの方がbよりでかいのが前提
  if (b == 0) return a; //aをbで割り切れたらreturn
  else gcd(b, a % b);
}
const int INF = 1<<30;
const int MOD = 1000000007;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int main(){
  int n; cin >> n;
  vector<int> a(n),idx(n);
  rep(i,n) cin >> a[i],a[i]--;
  rep(i,n) idx[a[i]] = i;
  set<int> s={-1,n};
  
  ll ans = 0;
  rep(x,n){
    int pos = idx[x];
    s.insert(pos);
    auto itr = s.find(pos);
    
    //left
    itr--;
    int l = *itr;
    
    //right
    itr++;itr++;
    int r = *itr;
    
    ans += (ll)(pos - l)*(r - pos)*(x+1);
  }
  
  cout << ans << endl;
  
  return 0;
}