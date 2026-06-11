#include <iostream> // プログラムの耳と口
#include <vector> // 超有能配列秘書
#include <algorithm> // みんな大好きソートと二分探索
#include <queue> // きゅーちゃん、だいすき
#include <string> // to_string
#include <functional> // 関数を変数に入れる子
#include <set> // 値の取得・挿入・削除を高速に
#include <map> // setの妹 これまた優秀
#include <random> // 乱択さん
#include <bitset>

#define DB cerr<<"D"<<endl
using namespace std; using ll=long long; using ld=long double; const int INF=1e9; const ll LINF=1e18; const double dINF = 1e18; const ld ldINF = 1e18; const double EPS = 1e-6;
template<typename T, typename U, typename O> void caut(T a, U b, O c){cout<<"("<<a<<","<<b<<","<<c<<") ";} template<typename T, typename U> void caut(T a, U b){cout<<"("<<a<<","<<b<<") ";} template<typename T> void caut(T a){cout<<"("<<a<<") ";};
using P=pair<ll,ll>;
const ll M = 1e9+7;
ll mod_pow(ll x, ll a) { ll an = 1; while(a > 0) { if (a&1) an = an * x % M; x = x * x % M; a >>= 1;} return an;}
ll adad(ll x) {return x*(x+1)/2;} // 1～xの総和
void add(ll& x, ll y) {x+=y; x%=M;}; void mul(ll& x, ll y) {x*=y; x%=M;}; template<typename T, typename U> void chmax(T& x, U y) {if (x<y) x=y;}; template<typename T, typename U> void chmin(T& x, U y) {if (x>y) x=y;}
bool vaild(int x, int y, int hh, int ww){return 0<=x&&x<hh&&0<=y&&y<ww;}
ll gcd(ll a, ll b) {if (b==0) return a; else return gcd(b, a%b);}
const int up[]={1,-1,0,0}, lf[]={0,0,1,-1};

int main() {
  int n,k; cin>>n>>k;
  int a[n]; for(int i=0;i<n;i++) cin>>a[i];

  sort(a,a+n);
  // ある部分まで必要、そこから不要→二分探索

  int ng = -1, ok = n;
  while(ok - ng > 1) {
    int md = (ng + ok) / 2;
    if (a[md] >= k) { // 明らかに必要
      ok = md; continue;
    }

    bool able[k]={}; able[0]=true;
    for(int i=0;i<n;i++) {
      if (i == md) continue;
      for(int j=k-1;j>=0;j--) {
        able[min(j+a[i],k)] |= able[j];
      }
    }

    bool use = false;
    for(int i=0;i<k;i++) {
      if (i + a[md] >= k) use |= able[i];
    }
    if (use) ok=md;
    else ng=md;
  }
  cout<<ok<<endl;
}