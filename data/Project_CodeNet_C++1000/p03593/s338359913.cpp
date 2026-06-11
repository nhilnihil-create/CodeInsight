#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(v) v.begin(), v.end()
#define allR(v) v.rbegin(), v.rend()
#define PRINT(v) for (auto x : (v)) cout <<x <<" " ; cout <<endl;
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
typedef pair<int,int> Pi;
const ll MOD = 1000000007;
const ll INF = 10000000000000000;
const int inf = 1001001001;
vector<int> x4 = {0, 1, 0, -1}, x8 = {0, 1, 1, 1, 0, -1, -1, -1};
vector<int> y4 = {1, 0, -1, 0}, y8 = {1, 1, 0, -1, -1, -1, 0, 1};
template<class T> inline bool chmin(T& a, T b){if (a>b){a = b; return true;}return false;}
template<class T> inline bool chmax(T& a, T b){if (a<b){a = b; return true;}return false;}
template<class T> inline T powerM(T a,T b){if (b==0) return 1;
T tmp = powerM(a,b/2); if (b%2==0) return tmp*tmp%MOD; else return tmp*tmp%MOD*a%MOD; }
template<class T> inline T power(T a,T b,T m=numeric_limits<T>::max()){ if (b==0) return 1;
  T tmp = power(a,b/2,m); if (b%2==0) return tmp*tmp%m; else return tmp*tmp%m*a%m; }
template<class T> inline T gcd(T a, T b){if (b==0) return a; return gcd(b, a%b);}
template<class T> inline T lcm(T a, T b){return a / gcd(a,b) * b;}
// ax+by=gcd(a,b)を解く
template<class T> inline T extgcd(T a,T b,T &x,T &y){if (b==0){x=1; y=0; return a;} T d=extgcd(b,a%b,y,x); y -= a/b*x; return d;}
void hey(){ cout <<"hey" <<endl; }

template<class T> struct edge { int to; T cost;};


bool check(int H,int W,vector<int> &alph){
  // H,W がともに偶数のときは4つの塊のみ
  // H,W の片方が偶数のときは4つの塊の他に2つの塊が偶数のやつ/2個存在
  // H,W がともに奇数のときは2つの塊がH/2+W/2個、1つが1個ある
  int not2 = 0;
  int not4 = 0;
  rep(i, alph.size()){
    if (alph[i]%2 != 0) not2++;
    else if (alph[i]%4 != 0) not4++;
  }
  if (H%2 == 0 && W%2 == 0){
    if (not2 > 0) return false;
    if (not4 > 0) return false;
    return true;
  }else if (H%2 == 0 || W%2 == 0){
    if (not2 > 0) return false;
    if (H%2==0 && not4 > H/2) return false;
    if (W%2==0 && not4 > W/2) return false;
    return true;
  }else{
    if (not2 > 1) return false;
    if (not4 > H/2+W/2) return false;
    return true;
  }
}

int main() {
  int H,W; cin >>H >>W;
  vector<int> alph(26);
  rep(i, H){
    string s; cin >>s;
    rep(j, W) alph[s[j]-'a']++;
  }
  cout <<(check(H,W,alph) ? "Yes" : "No") <<endl;
}
