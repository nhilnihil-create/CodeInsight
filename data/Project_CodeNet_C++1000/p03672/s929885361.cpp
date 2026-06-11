#include <bits/stdc++.h>
using namespace std;
using  ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
  string s;
  std::cin >> s;

  do {
    s.erase(s.size()-2);
  } while(s.substr(0,s.size()/2)!=s.substr(s.size()/2,s.size()/2));

  std::cout << s.size() << '\n';


  return 0;
}
