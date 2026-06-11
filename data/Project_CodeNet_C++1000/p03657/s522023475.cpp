#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int
main()
{
  ll A;
  cin >> A;
  ll B;
  cin >> B;
  cout << ((A % 3 == 0 || B % 3 == 0 || ((A + B) % 3 == 0)) ? "Possible"
                                                            : "Impossible")
       << endl;
  return 0;
}
