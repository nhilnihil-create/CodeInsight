#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  long long x;
  cin >> x;
  long long i = (x+5)/11; 
  for (; i*6+(i-1)*5 < x; ++i);
  long long res = i*6+(i-1)*5;
  cout << (res-6 >= x ? i*2-2 : i*2-1) << endl;

  return 0;
}

