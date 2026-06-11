#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const float pi = 3.1415926535;
unsigned GetDigit(unsigned num){
    return to_string(num).length();
}

int main() {
  int n;
  cin >> n;

  vector<int>a(n);
  for (int i = 0; i < n; i++) {
    cin >> a.at(i);
  }
  int x=1,cnt=0;
  while(x!= 2) {
    x = a.at(x-1);
    cnt++;
    if (cnt > n) {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << cnt << endl;
}