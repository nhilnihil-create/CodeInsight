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
ll gcd(ll x, ll y)
{
  if(x<y)
  {
    swap(x,y);
  }
  while(y>0)
  {
    ll r=x%y;
    x=y;
    y=r;
  }
  return x;
}
int main(){
  int x,y;cin>>x>>y;
  map<int,int> d;
  d[1]=1;
  d[3]=1;
  d[5]=1;
  d[7]=1;
  d[8]=1;
  d[10]=1;
  d[12]=1;
  d[4]=2;
  d[6]=2;
  d[9]=2;
  d[11]=2;
  d[2]=3;
  if(d[x]==d[y]){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
}