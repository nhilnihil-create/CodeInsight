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

int main()
{
  int n;
  cin >> n;
  vector<int> vec(n + 1);
  vec[0] = 0;
  for (int i = 1; i <= n;i++){
    cin >> vec[i];
  }
  int cnt = 0;
  vector<bool> totori(n + 1, false);
  for (int i = 1; i <= n;i++){
    if(vec[vec[i]] ==i ){
      totori[i] = true;
    }
      if(totori[i]){
        cnt++;
      }
  }
  cout << cnt/2 << endl;
}
