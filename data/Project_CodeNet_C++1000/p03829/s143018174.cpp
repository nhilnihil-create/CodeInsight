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
#include <math.h>
#include <iomanip> //setprecision
#include <limits>
using namespace std;

int main(){
  int n;
  long long a,b,x1,x1i,sum=0;
  cin >> n >> a >> b;
  vector<long long> x(n);
  for(int i = 0; i < n; i++){
    cin >> x.at(i);
  }
  x1=x.at(0);
  sort(x.begin(),x.end());
  for(int i = 0; i < n; i++){
    if(x.at(i)==x1){
      x1i=i;
      break;
    }
  }
  for(int i = 0; i < n-1; i++){
    if(i==x1i-1) continue;
    else sum+=min(a*(x.at(i+1)-x.at(i)),b);
  }
  if(x1i != 0) sum+=min(a*(x.at(n-1)-x.at(0)),b);
  cout << sum << endl;
}