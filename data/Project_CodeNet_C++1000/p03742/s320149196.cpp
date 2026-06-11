#include <iostream>
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <limits.h>
#include <math.h>
#include <functional>

#define repeat(i,n) for (long long i = 0; (i) < (n); ++ (i))
#define debug(x) cerr << #x << ": " << x << '\n'
#define debugArray(x,n) for(long long i = 0; (i) < (n); ++ (i)) cerr << #x << "[" << i << "]: " << x[i] << '\n'

using namespace std;

typedef long long ll;
typedef pair<int,int> Pii;
typedef vector<int> vint;
typedef vector<ll> vll;
const ll INF = INT_MAX;

int memo[200][200];

int dfs(int x,int y){
  if(memo[x][y] != 0) return memo[x][y];
  if(x<=1&&y<=1) return memo[x][y] = -1;
  for(int i=1;i*2<=x;i++){
    int a = dfs(x-2*i,y+i);
    if(a==-1){
      return memo[x][y] = 1;
    }
  }
  for(int i=1;i*2<=y;i++){
    int a = dfs(x+i,y-2*i);
    if(a==-1)
    return memo[x][y] = 1;
  }
  return memo[x][y] = -1;
}

int main() {
  /*
  repeat(i,100){
    repeat(j,100){
      cout << i << " " << j << " " << dfs(i,j) << endl;
    }
  }
  */
  ll X,Y;cin >> X >> Y;
  cout << (abs(X-Y)<=1? "Brown":"Alice") << endl;
  return 0;
}
