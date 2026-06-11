#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rrep(i,n) for (int i = 1; i <= (n); i++)
using ll = long long;
using Graph = vector<vector<int>>;


int keta(int n) {
  int cnt = 0;
  while(n > 0) {
    n /= 10;
    cnt++;
  }
  return cnt;
}

int main() {
  int n;
  cin >> n;
  int i = 0;
  while (pow(2,i) <= n) {
    i++;
  }
  i--;
  cout << pow(2,i) << endl;
}
