#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){

  int a,b;
  cin >> a >> b;

  if (a == 1) {
    a = 14;
  }
  if (b == 1) {
    b = 14;
  }

  if (a > b) {
    std::cout << "Alice" << '\n';
  } else if (a < b) {
    std::cout << "Bob" << '\n';
  } else {
    std::cout << "Draw" << '\n';
  }











}
