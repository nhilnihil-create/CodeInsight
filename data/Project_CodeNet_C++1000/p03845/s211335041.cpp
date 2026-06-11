#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int,string>;

int main() {
int n,m;
cin >> n;
vector<int> T(n);
rep(i,n) cin >> T.at(i);
int sum = 0;
rep(i,n) sum += T.at(i);
cin >> m;
vector<vector<int>> P(m,vector<int>(2));
rep(i,m){
  cin >> P.at(i).at(0);
  cin >> P.at(i).at(1);
}
rep(i,m){
  int ans = sum - T.at(P.at(i).at(0)-1) + P.at(i).at(1);
  cout << ans  << endl;
}


}
