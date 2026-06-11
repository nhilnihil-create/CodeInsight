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
int main(){ 
  long long int a,b,c=0,e=INT_MAX,f=0;
  cin>>a>>b;
  vector<long long int>d(a);
  rep(i,a){
    cin>>d[i];
  }
  rep(i,a-1){
    c+=max(d[i]+d[i+1]-b,f);
      //cout<<max(d[i]+d[i+1]-b,0);
    if(d[i]+d[i+1]-b>0)d[i+1]=max(f,d[i+1]-(d[i]+d[i+1]-b));
  }
  cout<<c;
  }
