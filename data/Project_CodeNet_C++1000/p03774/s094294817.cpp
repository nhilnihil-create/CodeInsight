#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  vector<int> a(n);
  vector<int> b(n);
  vector<int> c(m);
  vector<int> d(m);
  rep(i,n) cin >> a[i] >> b[i];
  rep(i,m) cin >> c[i] >> d[i];
  rep(i,n){
    int num = 0;
    int ps = 1000000000;
    rep(j,m){
      int s = abs(a[i]-c[j])+abs(b[i]-d[j]);
      if(s < ps){
      	num = j+1;
        ps = s;
      }
  	}
    cout << num << endl;
    ps = 1000000000;
  }
}
