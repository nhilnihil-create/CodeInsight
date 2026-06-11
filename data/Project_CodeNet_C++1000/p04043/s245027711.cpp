#include <bits/stdc++.h>
using namespace std;

int main()
{
  int seven = 0, five = 0;

  for (int i = 0; i < 3; ++i) {
    int n; cin >> n;
    
    if (n == 7) ++seven;
    else if (n == 5) ++five;
  }

  cout << (five == 2 && seven == 1 ? "YES\n" : "NO\n");
}