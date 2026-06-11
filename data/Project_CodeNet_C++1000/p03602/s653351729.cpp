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

int n;
int a[300][300];
int f[300][300];

int main()
{
  cin >> n;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> a[i][j];
    }
  }

  for(int k = 0; k < n; k++){
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        if(a[i][k] + a[k][j] < a[i][j]){
          cout << -1 << endl;
          return 0;
        }
      }
    }
  }

  for(int k = 0; k < n; k++){
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        if(a[i][k] + a[k][j] == a[i][j] && a[i][k] && a[k][j]){
          f[i][j] = 1;
        }
      }
    }
  }


  ll ans = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j <= i; j++){
      if(!f[i][j]) ans += a[i][j];
    }
  }

  cout << ans << endl;

  return 0;
}
