# include <iostream>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  
  string ans = "";
  if (a <= 0 && b >= 0) ans = "Zero";
  if (a > 0 && b > 0) ans = "Positive";
  else if (a < 0 && b < 0) {
    int num = b - a + 1;
    if (num % 2 == 0) ans = "Positive";
    else ans = "Negative";
  }
  
  cout << ans << endl;
  
  return 0;
}