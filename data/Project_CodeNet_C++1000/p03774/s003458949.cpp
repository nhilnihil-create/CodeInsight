#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <cstdint>
#include <numeric>
#define INF 1000000000
#define LLINF 2000000000000000
#define MOD 1000000007
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define LOOP(i,N) for(int i=0;i<N;i++)
#define LOOP1(i,N) for(int i=1;i<=N;i++)
typedef pair<int,int> P;
typedef pair<int,pair<int,int> > PP;
// #define int long long

int abs(P a, P b){
  int x = a.first-b.first;
  if(x<0) x *= -1;
  int y = a.second-b.second;
  if(y<0) y *= -1;

  return x+y;
}

signed main(){
  int n;
  cin >> n;
  int m;
  cin >> m;
  P a[n], b[m];
  LOOP(i,n){
    int x,y;
    cin >> x >> y;
    a[i] = P(x,y);
  }
  LOOP(i,m){
    int x,y;
    cin >> x >> y;
    b[i] = P(x,y);
  }
  int go[n];
  LOOP(i,n){
    go[i] = 0;
    LOOP(j,m){
      if(
        abs(a[i], b[j]) < abs(a[i], b[go[i]])
      ){
        go[i] = j;
      }
    }
  }
  LOOP(i,n){
    cout << go[i]+1 << endl;
  }
}
