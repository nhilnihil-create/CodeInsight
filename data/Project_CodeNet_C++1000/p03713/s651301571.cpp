#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(v) v.begin(), v.end()
#define PRINT(v) for (auto x : (V)) cout <<x <<" " <<endl;
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
const ll MOD = 1000000007;
const ll INF = 10000000000000000;
vector<int> x4 = {0, 1, 0, -1}, x8 = {0, 1, 1, 1, 0, -1, -1, -1};
vector<int> y4 = {1, 0, -1, 0}, y8 = {1, 1, 0, -1, -1, -1, 0, 1};
template<class T> struct edge { int from, to; T cost;};
template<class T> inline bool chmin(T& a, T b){if (a>b){a = b; return true;}return false;}
template<class T> inline bool chmax(T& a, T b){if (a<b){a = b; return true;}return false;}
template<class T> inline T powerM(T a,T b){if (b==0) return 1;
T tmp = powerM(a,b/2); if (b%2==0) return tmp*tmp%MOD; else return tmp*tmp%MOD*a%MOD; }
template<class T> inline T power(T a,T b,T m){ if (b==0) return 1;
  T tmp = power(a,b/2,m); if (b%2==0) return tmp*tmp%m; else return tmp*tmp%m*a%m; }
template<class T> inline T gcd(T a, T b){if (b==0) return a; return gcd(b, a%b);}
template<class T> inline T lcm(T a, T b){return a / gcd(a,b) * b;}
// ax+by=gcd(a,b)を解く
template<class T> inline T extgcd(T a,T b,T &x,T &y){if (b==0){x=1; y=0; return a;} T d=extgcd(b,a%b,y,x); y -= a/b*x; return d;}
void hey(){ cout <<"hey" <<endl; }


int H,W;

void input() {
  cin >>H >>W;
  if (H > W) swap(H, W);
  // 常に横長とする
}

int main() {
  input();

  ll res = 100000000000000;
  for (int i=0; i<H-1; i++){
    ll h = H, w = W;
    // i行目の次の所で1回目切る
    ll c1 = w * (i+1);
    h -= i+1;
    // 現在h*wのフィールドになっている
    // h, wのどちらかが偶数なら半分こ
    if (h*w % 2 == 0){
      chmin(res, abs(c1 - h*w/2));
    }else{
      ll tmp1 = (h*w-h) / 2, tmp2 = (h*w+h) / 2;
      ll tmp = max((ll)h, max(abs(c1 - tmp1), abs(c1 - tmp2)));
      chmin(res, tmp);
      tmp1 = (h*w-w) / 2, tmp2 = (h*w+w) / 2;
      tmp = max((ll)h, max(abs(c1 - tmp1), abs(c1 - tmp2)));
      chmin(res, tmp);
    }
  }
  for (int j=0; j<W-1; j++){
    ll h = H, w = W;
    // j行目の次の所で1回目切る
    ll c1 = h * (j+1);
    w -= j+1;
    // 現在h*wのフィールドになっている
    // h, wのどちらかが偶数なら半分こ
    if (h*w % 2 == 0){
      chmin(res, abs(c1 - h*w/2));
    }else{
      ll tmp1 = (h*w-h) / 2, tmp2 = (h*w+h) / 2;
      ll tmp = max((ll)h, max(abs(c1 - tmp1), abs(c1 - tmp2)));
      chmin(res, tmp);
      tmp1 = (h*w-w) / 2, tmp2 = (h*w+w) / 2;
      tmp = max((ll)h, max(abs(c1 - tmp1), abs(c1 - tmp2)));
      chmin(res, tmp);
    }
  }

  cout <<res <<endl;
}