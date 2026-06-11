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
#define answer cout << ans << endl;
signed _main(); signed main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> using v = vector<T>;
template<class T> using vv = vector<v<T>>;
const int MOD=1e9+7;
const long long INF = 1LL << 60;
using P=pair<int,int>;

signed _main(){
  int K,T; cin >> K >> T;
  v<P> a(T);
  rep(i,T){
    cin >> a[i].first;
    a[i].second=i;
  }
  int banned_index=114514;
  rep(i,K){
    rep(j,T){
      if(a.size()==1){
        cout << a[0].first-1 << endl;
        return 0;
      }
      sort(a.begin(),a.end());
      reverse(a.begin(),a.end());
      int index=0;
      if(a[index].second==banned_index){
        index++;
      }
      a[index].first--;
      //fore(k,a) cout << "a " << k.first << endl;
      //cout << endl;
      //cout << a[index].second << endl;
      banned_index=a[index].second;
      if(a[index].first==0){
        swap(a[index],a[a.size()-1]);
        a.pop_back();
      }
    }
  }
  return 0;
}
