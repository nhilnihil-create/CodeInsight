#include <bits/stdc++.h>
using namespace std;

int main(){
  int64_t from,to;
  cin >> from >> to;
  const int64_t absfrom= abs(from);
  const int64_t absto= abs(to);

  int64_t ans= (absfrom <= absto) ? ( (from >= 0 && to >= 0) ? absto- absfrom
                                     :(from <  0 && to <  0) ? absto- absfrom+ 2
                                                             : absto- absfrom+ 1)
                                  : ( (from > 0 && to >  0) ? absfrom- absto+ 2
                                     :(from < 0 && to <= 0) ? absfrom- absto
                                                            : absfrom- absto+ 1);

  cout << ans << endl;
}