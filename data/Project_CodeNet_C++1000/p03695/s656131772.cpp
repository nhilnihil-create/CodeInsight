#include <iostream>      // cout, endl, cin
#include <string>        // string, to_string, stoi
#include <vector>        // vector
#include <algorithm>     // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility>       // pair, make_pair
#include <tuple>         // tuple, make_tuple
#include <cstdint>       // int64_t, int*_t
#include <cstdio>        // printf
#include <map>           // map
#include <queue>         // queue, priority_queue
#include <set>           // set
#include <stack>         // stack
#include <deque>         // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset>        // bitset
#include <cctype>        // isupper, islower, isdigit, toupper, tolower

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vpii = vector<pair<int, int>>;

int main()
{
  int n;
  cin >> n;
  int min_cnt = 0, max_cnt = 0;
  vi vec(8, 0);
  vi a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    if (a[i] / 400 < 8)
      vec[a[i] / 400]++;
    if (a[i] / 400 >= 8)
      max_cnt++;
  }
  for (int i = 0; i < 8; i++)
  {
    if (vec[i] != 0)
    {
      min_cnt++;
      max_cnt++;
    }
    
  }
  if(min_cnt==0){min_cnt++;}
  cout << min_cnt << " " << max_cnt << endl;
}
