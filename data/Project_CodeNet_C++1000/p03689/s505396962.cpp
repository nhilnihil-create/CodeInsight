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

#define repeat(i,n) for (long long i = 0; (i) < (n); ++ (i))
#define debug(x) cerr << #x << ": " << x << '\n'
#define debugArray(x,n) for(long long i = 0; (i) < (n); ++ (i)) cerr << #x << "[" << i << "]: " << x[i] << '\n'

using namespace std;

typedef long long ll;
typedef pair<int,int> Pii;
typedef vector<int> vint;
typedef vector<ll> vll;
const ll INF = INT_MAX;
const ll MOD = 998244353;

int main() {
  int H,W,h,w;cin >> H >>W >> h >> w;
  if(H%h==0&&W%w==0){
    cout <<"No" <<endl;
    return 0;
  }
  cout << "Yes" <<endl;
  ll out=1e6;
  repeat(i,H){
    repeat(j,W){
      if(H%h!=0){
        if(i%h==h-1){
          cout << -(h-1)*out-1;
        }else{
          cout << out;
        }
      }else{
        if(j%w==w-1){
          cout << -(w-1)*out-1;
        }else{
          cout << out;
        }
      }
      cout <<(j<W-1? " ":"\n");
    }
  }
  return 0;
}
