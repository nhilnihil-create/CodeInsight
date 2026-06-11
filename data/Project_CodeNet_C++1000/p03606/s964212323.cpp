#include <iostream>

using namespace std;

string st;

int main() {

  int n, s = 1e9, m = 0, l = 0;
  cin >> n;
  for(int i =1;i <= n;i++){
    cin >> s >> l;
    m += l - s + 1;
  }
  cout << m;
  return 0;
}
