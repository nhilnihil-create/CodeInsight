#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long ll;

int main()
{
  int n;
  int p[100001];
  int ans = 0;

  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> p[i];
  }

  for(int i = 1; i < n; i++){
    if(p[i] == i){
      ans++;
      swap(p[i], p[i+1]);  
    }
  }

  if(p[n] == n) ans++;

  cout << ans << endl;

  return 0;
}
