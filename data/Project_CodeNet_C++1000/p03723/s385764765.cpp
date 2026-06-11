#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  long long a,b,c;
  cin >> a >> b >> c;

  if(a % 2 == 1 || b % 2 == 1 || c % 2 == 1) {
    cout << "0" << endl;
    return 0;
  }

  if(a == b && b == c) {
    cout << "-1" << endl;
    return 0;
  }

  long long count = 0;
  long long tmp_a,tmp_b,tmp_c;
  while(true) {
    tmp_a = a;
    tmp_b = b;
    tmp_c = c;
    a = tmp_b/2 + tmp_c/2;
    b = tmp_c/2 + tmp_a/2;
    c = tmp_a/2 + tmp_b/2;
    count++;
    if(a % 2 == 1 || b % 2 == 1 || c % 2 == 1) break;
  }
  cout << count << endl;
  return 0;
}
