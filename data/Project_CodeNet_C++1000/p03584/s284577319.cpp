#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

#define maxN 100000
int N, K;
int a[maxN];
ll b[maxN];

//ｘに対してスコアはいくつになるか
ll check(int x){
  ll res = 0LL;
  for(int i = 0; i < N; i++){
    if((x | a[i]) <= x){
      res += b[i];
    }
  }
  return res;
}

//候補の数がｘ、見ているビットがy
ll dfs(int x, int y){
  //cout << x << " " << y << endl;
  if(y == 0){
    ll ans = check(x);
    return ans;
  }

  //xのyビットが０
  if((x & (1 << y)) == 0){
    return dfs(x, y - 1);
  }
  else {
    ll res1 = dfs(x, y - 1);

    x -= (1 << y);
    for(int i = 0; i < y; i++){
      x |= (1 << i);
    }
    ll res2 = check(x);

    return max(res1, res2);
  }
}

int main(){
  cin >> N >> K;
  for(int i = 0; i < N; i++) cin >> a[i] >> b[i];

  cout << dfs(K, 30) << endl;
  return 0;
}
