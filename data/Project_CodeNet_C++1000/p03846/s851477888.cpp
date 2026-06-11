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

const int p=1e9+7;

ll pow(ll x, ll n) { //x^nの計算
  ll res = 1;
  while (n > 0) {
    if (n & 1){
      res = res*x%p;  // n の最下位bitが 1 ならば x^(2^i) をかける
    }
    x = x*x%p;
    n >>= 1;  // n を1bit 左にずらす
  }
  return res;
}

int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  for(int i=0;i<N;i++){
    cin >> A[i];
  }
  if(N%2==0){
    vector<int> B(N/2,0);
    for(int i=0;i<N;i++){
      B[(N+1-A[i])/2-1]++;
    }
    for(int i=0;i<N/2;i++){
      if(B[i]!=2){
        cout << 0 << endl;
        return 0;
      }
    }
    cout << pow(2,N/2) << endl;
    return 0;
  }
  else if(N%2==1){
    vector<int> B((N+1)/2,0);
    for(int i=0;i<N;i++){
      B[(N+1-A[i])/2-1]++;
    }
    for(int i=0;i<(N-1)/2;i++){
      if(B[i]!=2){
        cout << 0 << endl;
        return 0;
      }
    }
    cout << pow(2,(N-1)/2) << endl;
    return 0;
  }
}