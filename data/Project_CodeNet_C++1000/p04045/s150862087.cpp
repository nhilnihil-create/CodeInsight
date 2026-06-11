#include <bits/stdc++.h>
#define rep(i, n) for(int i= 0; i < (n); i++)
using ll= long long int;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll mod= 1e9 + 7;


int main(){
  int n;
  int k;
  cin >>n >>k;
  char a[k];
  rep(i,k)cin >> a[i];
  for(int i=n;i<n*20;i++){
    string g=to_string(i);
    int q=g.size();
    bool e=0;
    rep(t,q){
      rep(tt,k){
        if(a[tt]==g[t]){e=1;break;}
      }
    }
    if(e){continue;}
    cout << i << endl;
    break;
  }
}