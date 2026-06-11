#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  string st;
  cin >> st;
  int n = 0,w = 0,s = 0,e = 0;
  rep(i,0,st.size()){
    if(st[i] == 'N') n++;
    if(st[i] == 'W') w++;
    if(st[i] == 'S') s++;
    if(st[i] == 'E') e++;
  }
  bool f = false;
  if((n == 0 && s != 0)||(n != 0 && s == 0)) f = true;
  if((w == 0 && e != 0)||(w != 0 && e == 0)) f = true;
  if(f) cout << "No" << endl;
  else cout << "Yes" << endl;
}