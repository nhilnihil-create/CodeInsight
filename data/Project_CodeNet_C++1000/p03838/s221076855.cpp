#include <bits/stdc++.h>
 
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,n) for(int i=1;i<=(n);i++)
#define lol long long
#define SUM(n) ((n)+1)*(n)/2　//1〜nまでの総和を求める式
#define mp make_pair
#define fi first
#define se second
#define pu push_back
#define SYOU(x) setprecision(x+1) //小数点桁数を指定する
#define abs(x,y) (max(x,y)-min(x,y))
#define all(v) v.begin(),v.end()
#define UPDight(a,b) (a+b-1)/b //小数点切り上げ 
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
const int MOD=int(1e9)+7; 
using namespace std;
using pii = pair<int,int>;
typedef vector<int> vit;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int x, y;
  cin >> x >> y;
  lol a, b, c, d;
  a = (x <= y ? y - x : LINF);
  b = (x <= y * -1 ? 1 + ((y * -1) - x) : LINF);
  c = (x * -1 <= y ? 1 + (y - (x * -1)) : LINF);
  d = (x * -1 <= y * -1 ? 2 + (y * -1 - x * -1) : LINF);
  cout << min(min(a, b), min(c, d)) << '\n';
  return 0;
}
