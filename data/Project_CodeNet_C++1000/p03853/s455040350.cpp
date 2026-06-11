#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int,string>;

int main() {
int h,w;
cin >> h >> w;
vector<vector<char>> a(h,vector<char>(w));

rep(i,h)rep(j,w) cin >> a.at(i).at(j);


rep(i,2*h)rep(j,w){
  cout <<a.at((i+2)/2-1).at(j);
  if(j == w-1) cout << endl;
}

}
