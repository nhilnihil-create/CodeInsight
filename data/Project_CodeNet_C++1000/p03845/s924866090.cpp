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
using namespace std;
using ll = long long;

int main(){
  int N;
  cin >> N;
  vector<int> T(N);
  for(int i=0;i<N;i++){
    cin >> T[i];
  }
  int sum=0;
  for(int i=0;i<N;i++){
    sum+=T[i];
  }
  int M;
  cin >> M;
  for(int i=0;i<M;i++){
    int P,X;
    cin >> P >> X;
    cout << sum-T[P-1]+X << endl;
  }
}