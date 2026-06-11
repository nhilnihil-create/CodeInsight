#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>
#include <complex>
#include <array>
#include <functional>
#include <stack>
#include <iomanip>
#include <limits>
using namespace std;
#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<double> VD;

#define INF 1e+9
#define MAX_V 300

struct edge {
    int to;
    int cost;
};
using P = pair<ll, ll>;
int main(){
  ll n;cin>>n;
  set<ll> d;
  for(int i=0;i<n;i++){
    ll tmp;cin>>tmp;
    if(d.find(tmp)!=d.end()){
      d.erase(tmp);
    }else{
      d.insert(tmp);
    }

  }
  cout<<d.size()<<endl;
}
