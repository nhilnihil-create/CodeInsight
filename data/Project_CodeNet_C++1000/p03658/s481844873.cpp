#include <iostream>
#include <numeric>
#include <stdio.h>
#include <iomanip>
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
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)
 

int main(){
  ll N,K,an=0;
  
  cin>>N>>K;
  vector<ll> vec(N);
	for (int i = 0; i < N; i++) {
  		cin >> vec.at(i);
	}
  sort(vec.begin(),vec.end());
  reverse(vec.begin(),vec.end());
  rep(i,K){
  an+=vec.at(i);
  }

  cout<<an<<endl;
}