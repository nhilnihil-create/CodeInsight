#include <cstdio>
#include <cstring>
#include <cmath>
#include <utility>
#include <iostream>
#include <functional>
#include <bitset>
#include <algorithm>
#include <vector>
#include <forward_list>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <numeric>
#define ll long long int
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
int mx4[] = {0,1,0,-1};
int my4[] = {1,0,-1,0};
int INF = 2e6;
 
 
int main(){
  int n,k;
  cin >> n >> k;
  vector<int> l(n);
  rep(i,n) cin >> l[i];
  sort(l.rbegin(),l.rend());
  int ans = 0;
  rep(i,k) ans += l[i];
  cout << ans << endl;
}
