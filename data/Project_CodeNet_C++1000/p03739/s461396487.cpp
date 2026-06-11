#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,a,b) for(int i=(a);i<(b);++i)

template<class T> inline void chmin(T& a, T b) {if (a > b) a = b;}
template<class T> inline void chmax(T& a, T b) {if (a < b) a = b;}

//vector出力
template <class T>ostream &operator<<(ostream &o,const vector<T>&v){
  o<<"{";
  for(int i=0;i<(int)v.size();i++) o << (i>0?", ":"") << v[i];
  o<<"}";
  return o;
}




int main() {
  int n;
  cin >> n;
  vector<ll> A(n);
  ll a,now1=0,cnt1=0,now2=0,cnt2=0;
  rep(i,n) cin >> A[i];

  rep(i,n) {
    now1 += A[i];
    now2 += A[i];
    if (now1<=0) {
      cnt1+=abs(now1)+1;now1=1;
    }
    if (now2>=0) {
      cnt2+=abs(now2)+1;now2=-1;
    }
    swap(now1,now2);swap(cnt1,cnt2);
  }
  cout << min(cnt1,cnt2) << endl;
}