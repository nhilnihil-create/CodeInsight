#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll = long long int;

template <class T> ostream &operator<<(ostream &os, vector<T> &v) {
  for (auto i = v.begin(); i != v.end(); i++) {
    os << *i << " ";
  }
  return os;
}

// -------------------------------------------


void solve(long long N, std::string S){
  int l = 0;
  int r = 0;
  for(auto c : S) {
    if(c == '(') l++;
    if(c == ')') {
      if(l > 0) l--;
      else r++;
    }
  }
  rep(i,r) std::cout << '(';
  std::cout << S;
  rep(i,l) std::cout << ')';
  std::cout << std::endl;
}

int main(){
    long long N;
  scanf("%lld",&N);
  std::string S;
  std::cin >> S;
    solve(N, S);
    return 0;
}
