#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  int n;
  cin >> n;
  bool flag = false;
  if(n / 10 == 9) flag = true;
  else if(n % 10 == 9) flag = true;
  
  if(flag) cout << "Yes" << endl;
  else cout << "No" << endl;
}