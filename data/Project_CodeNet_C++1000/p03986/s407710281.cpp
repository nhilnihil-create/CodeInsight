#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const int MAX = 510000;

int main() {
  string X;
  cin >> X;
  int stack = 0, puyo = 0;
  for (int i=0; i<X.size(); i++) {
    if (X[i]=='S') stack++;
    else if (stack>0) {
      stack--;
      puyo++;
    }
  }
  cout << X.size()-2*puyo << endl;
  return 0;
}