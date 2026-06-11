#include<iostream>
#include<string>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;

  string ans;

  if (b < 0) {
    if ((a - b - 1) % 2 == 0) ans = "Positive";
    else ans = "Negative";
  } else if (a <= 0 && 0 <= b) ans = "Zero";
  else ans = "Positive";

  cout << ans << endl;
  return 0;
}
