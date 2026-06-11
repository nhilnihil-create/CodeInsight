#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;
const int MOD = 1e9+7;
using ll = long long;
using vi = vector<int>;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ALL(x) x.begin(), x.end()
int main() {
  int a,b;
  cin >> a >> b;
  int c = a - b + 1;
  vector<vector<char>> deka(a, vector<char>(a));
  vector<vector<char>> tiisa(b, vector<char>(b));
  for (int i = 0; i < a; i++) {
    for (int j = 0; j < a; j++) {
      cin >> deka.at(i).at(j);
    }
  }
   for (int i = 0; i < b; i++) {
    for (int j = 0; j < b; j++) {
      cin >> tiisa.at(i).at(j);
    }
  }
  bool exist = false;
  for(int ss = 0;ss<c;ss++){
  for(int tt = 0;tt<c;tt++){
   if(ss+b-1>=a||tt+b-1>=a) continue;
    bool match = true;
   for (int i = 0; i < b; i++) {
    for (int j = 0; j < b; j++) {
      if(tiisa.at(i).at(j) != deka.at(i+ss).at(j+tt)) match = false;
    }
   }
    if(match) exist = true;
    }
  }
  if(exist) cout << "Yes";
  else cout << "No";
}
