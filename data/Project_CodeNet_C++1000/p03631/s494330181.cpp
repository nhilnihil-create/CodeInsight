#include <iostream>

using namespace std;

int reverse ( int x ) {
  int ans = 0, rank = 1;
  int rerank = 1;

  while( rank < x ) rank *= 10; rank /= 10;

  while ( x > 0 ) {
    int tmp = x/rank;
    x = x % rank;
    ans += tmp*rerank;
    rank /= 10;
    rerank *= 10;
  }

  return ans;
}

int main()
{
  int n;
  cin >> n;

  if ( reverse(n) == n ) cout << "Yes\n";
  else cout << "No\n";
}
