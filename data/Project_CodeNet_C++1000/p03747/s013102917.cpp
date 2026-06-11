#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
using namespace std;
#define MOD 1000000007
#define INF (1<<29)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;

#define max(x, y) ((x)>(y)?(x):(y))
#define min(x, y) ((x)<(y)?(x):(y))
Int n, l, t;
Int x[216000], w[216000];
Int ans[216000];

int main(){
  cin >> n >> l >> t;
  for(Int i = 0;i < n;i++){
    cin >> x[i] >> w[i];
  }
  Int start = 0;
  Int crush = 0;
  while(start < n && w[start] == 2)start++;
  if(start == n){start = 0;goto calc;}
  for(Int i = 0;i < n;i++){
    if(w[start] == w[i])continue;
    Int dist = x[i] - x[start];
    if(dist < 0)dist += l;
    if(dist > t*2)continue;
    crush += 1 + (2*t-dist) /l;
  }
 calc:
  for(Int i = 0;i < n;i++){
    if(w[i] == 1)
      x[i] = (x[i] + t) % l;
    else
      x[i] = ((x[i] - t) % l + l) % l;
  }
  Int pos = x[start];
  sort(x, x + n);
  Int k = 0;
  while(x[k] != pos)k++;
  if(k < n-1 && x[k+1] == x[k])k++;
  for(Int i = 0;i < n;i++){
    ans[(start + crush + i) % n] = x[(k+i)%n];
  }
  for(Int i = 0;i < n;i++)cout << ans[i] << endl;
  return 0;
}