#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
  int a,b,c;
  std::cin >> a>>b>>c;

  if(a+b == c || a+c == b || b+c == a){
    std::cout << "Yes" << '\n';
  }
  else{
    std::cout << "No" << '\n';
  }
  return 0;
}