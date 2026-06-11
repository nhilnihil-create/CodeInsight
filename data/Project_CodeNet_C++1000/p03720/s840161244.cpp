#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int,string>;

int main() {
int n,m;
cin >> n >> m;
vector<int> a(n,0);

rep(i,m){
  int x,y;
  cin >> x >> y;
  a.at(x-1)++;
  a.at(y-1)++;
}
rep(i,n) cout << a.at(i) << endl;
  }
