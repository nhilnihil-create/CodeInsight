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
  long long  a,b,f=0,g=0;cin>>a;
  map<long long ,long long >c;
  rep(i,a){
    cin>>b;
    b*=-1;
    if(c.count(b))c[b]++;
    else c[b]=1;
  }
  auto d=c.end(),e=c.begin();
  for(auto i=e;i!=d;i++){
    if(i->second>1&&f==0){
      f=i->first;
      c[i->first]-=2;
      }
      if(i->second>1&&f!=0&&g==0)g=i->first;
      if(f!=0&&g!=0)break;
  }
  cout<<f*g;
  }
