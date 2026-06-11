
#include<iostream>
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
#include <iomanip>//setprecision
#include<math.h>
#include <functional>
#include<climits>
using namespace std;
#define rep(i, n)        for(int i=0; i<(int)(n); ++i)
#define ll  long long 
#define mod 1000000007
  vector<ll>to[1000005];
int main(){
  ll a,b,c;cin>>a>>b>>c;
  for(ll i=a;i<=a*b;i+=a){
    if(i%b==c){
      cout<<"YES";
      return 0;
    }
  }
  cout<<"NO";
}