# include <iostream>
using namespace std;

int a, b, c;

int main() {
  cin >> a >> b >> c;
  int ans = 0;
  while (a % 2 == 0 && b % 2 == 0 && c % 2 == 0) {
    if (a == b && b == c) {
      ans = -1;
      break;
    }
    
    int half_a = a / 2;
    int half_b = b / 2;
    int half_c = c / 2;
    
    a = half_b + half_c;
    b = half_a + half_c;
    c = half_a + half_b;
    
    ans++;
  }
  cout << ans << endl;
  
  return 0;
}