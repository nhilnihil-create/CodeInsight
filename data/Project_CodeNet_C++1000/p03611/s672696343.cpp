#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <cmath>
#include <limits>
using namespace std;
using ll = long long;

int main(){
  int N;
  cin >> N;
  vector<int> num(1e5+5);
  for(int i=0;i<N;i++){
    int a;
    cin >> a;
    num[a]++;
  }
  int sum=num[0]+num[1]+num[2];
  int ans=sum;
  for(int i=1;i<1e5;i++){
    sum=sum-num[i-1]+num[i+2];
    ans=max(ans,sum);
  }
  cout << ans << endl;
}