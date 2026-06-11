#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  int h,w;
  cin >> h >> w;
  vector<string>data(h);
  rep(i,0,h) cin >> data[i];
  rep(i,0,w+2) cout << "#";
  cout << "" << endl;
  rep(i,0,h) cout << "#" << data[i] << "#" << endl;
  rep(i,0,w+2) cout << "#";
  cout << "" << endl;
}