#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <climits>
#include <iomanip>
#include <set>
using namespace std;
typedef long long ll;
int main(){
  int n,m,k;
  cin >> n >> m >>k;
  bool res = false;
  for(int i = 0;i <= n;i++){
    for(int j = 0;j <= m;j++){
      if(i * (m - j) + j * (n - i) == k)res = true;
    }
  }
  if(res)cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}