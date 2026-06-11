#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <iomanip>
#include <cmath>
#include <stack>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll = long long int;

template <class T> ostream &operator<<(ostream &os, vector<T> &v) {
  for (auto i = v.begin(); i != v.end(); i++) {
    os << *i << " ";
  }
  return os;
}

const long long MOD = 1000000007;

int main(){
  int a, b, x;
  cin>>x>>a>>b;
  if(a>=b)
    std::cout << "delicious" << std::endl;
  else if(b-a <= x)
    std::cout << "safe" << std::endl;
  else
    std::cout << "dangerous" << std::endl;
  return 0;
}
