#include <iostream>
#include <vector>
#include <algorithm>

constexpr int NOT_EXIST = -1;
typedef std::vector<int> digits;

int numeral(const digits& ds, const digits& xs) {
  int d = 1;
  int r = 0;
  for( int x : xs ) {
    if( x == NOT_EXIST ) return r;
    r += ds[x] * d;
    d *= 10;
  }
  return r;
}

void increment(const digits& ds, digits& xs) {
  for( auto& x: xs ) {
    const int last = x;
    const int nx = x + 1;
    x = nx % ds.size();
    if( last == -1 || x != 0 ) {
      return;
    }
  }
}

int main() {
  int n, k;
  std::cin >> n >> k;

  digits denied;
  for( size_t i = 0; i < k; ++i ) {
    int d;
    std::cin >> d;
    denied.push_back(d);
  }

  digits allows;
  for( int a = 0; a <= 9; ++a ) {
    if( std::find(denied.begin(), denied.end(), a) == denied.end() ) {
      allows.push_back(a);
    }
  }

  digits xs(6, NOT_EXIST);
  while( numeral(allows, xs) < n ) {
    increment(allows, xs);
  }

  std::cout << numeral(allows, xs) << std::endl;
}