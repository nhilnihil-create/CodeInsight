#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c;

  cin >> a >> b >> c;

  if (a - b == b - c){
    std::cout << "YES" << '\n';
    return 0;
  }


  cout << "NO" <<'\n';
  return 0;
}