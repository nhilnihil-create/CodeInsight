#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int,string>;

int main() {
  int n;
  cin >> n;
  int sum = 0;
  for(int i = 1; i<= n ;i++){
    sum+=i;
  }
  cout << sum << endl;
}