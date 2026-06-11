#include<bits/stdc++.h>
#define REP(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
const ll MOD = 1000000007;

int main() {
  int a, b;
  cin >> a >> b;
  if (a + b >= 10) {
    cout << "error" << endl;
  } else {
    cout << a + b << endl;
  }
  return 0;
}