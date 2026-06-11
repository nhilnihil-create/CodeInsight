#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (ll i = m; i < (n); i++)

using ll = long long;
using pii = pair<int, int>;
using Vi = vector<int>;

int main() {
  int x,y;
  cin >> x>>y;
  bool b = false;
  if(x==2){
    if(y==2){
      b = true;
    }
  }
  else if(x==4||x==6||x==9||x==11){
    if(y==4||y==6||y==9||y==11){
      b = true;
    }
  }
  else{
    if(y!=2&&y!=4&&y!=6&&y!=9&&y!=11){
      b = true;
    }
  }
  if(b) cout << "Yes" << endl;
  else cout << "No" << endl;
}
      