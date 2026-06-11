#include <iostream>
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <limits.h>
#include <math.h>
#include <functional>
#include <bitset>

#define repeat(i,n) for (long long i = 0; (i) < (n); ++ (i))
#define debug(x) cerr << #x << ": " << x << '\n'
#define debugArray(x,n) for(long long i = 0; (i) < (n); ++ (i)) cerr << #x << "[" << i << "]: " << x[i] << '\n'
#define debugArrayP(x,n) for(long long i = 0; (i) < (n); ++ (i)) cerr << #x << "[" << i << "]: " << x[i].first<< " " << x[i].second << '\n'

using namespace std;

typedef long long ll;
typedef pair<int,int> Pii;
typedef vector<int> vint;
typedef vector<ll> vll;
const ll INF = LLONG_MAX/10;
const ll MOD = 1e9+7;

int main(){
  ll H,W,d;cin >> H >> W >> d;
  vector<string> c(H,string(W,'?'));
  for(int i=0;i<=1200;i++){
    for(int j=0;j<=1200;j++){
      if((i+j)%2==1)continue;
      int y = i-600,x = j;
      int nx = (x+y)/2,ny = (x-y)/2;
      if(nx<0||W<=nx||ny<0||H<=ny) continue;
      char color='?';
      if(i/d%2==0&&j/d%2==0){
        color = 'R';
      }else if(i/d%2==0&&j/d%2==1){
        color = 'Y';
      }else if(i/d%2==1&&j/d%2==0){
        color = 'G';
      }else if(i/d%2==1&&j/d%2==1){
        color = 'B';
      }
      c[ny][nx] = color;
    }
  }
  repeat(i,H){
    cout << c[i] << endl;
  }
  return 0;
}
