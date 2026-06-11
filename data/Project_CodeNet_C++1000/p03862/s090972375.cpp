#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define SZ(x) ((int)(x).size())
#define rep(i,n) for(int i=0;i<(n);++i)
#define fore(i,a) for(auto &i:a)
#define min(...) min({__VA_ARGS__})
#define max(...) max({__VA_ARGS__})
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;
#define ALL(x) (x).begin(),(x).end()
signed _main(); signed main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> using v = vector<T>;
template<class T> using vv = vector<v<T>>;
const int MOD=1e9+7;
const long long INF = 1LL << 60;
using P=pair<int,int>;

signed _main(){
  int N,x; cin >> N >> x;
  v<int> a(N);
  rep(i,N) cin >> a[i];
  int ans=0;
  if(a[0]>x){
    ans+=a[0]-x;
    a[0]=x;
  }
  for(int i=1;i<N;i++){
    int num=a[i-1]+a[i];
    if(num>x){
      if(a[i]>=num-x){
        ans+=num-x;
        a[i]-=num-x;
      }
      else{
        ans+=num-x;
        a[i]=0;
        a[i-1]-=num-x-a[i];
      }
    }
  }
  cout << ans << endl;

  return 0;
}
