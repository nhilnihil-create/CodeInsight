#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <climits>
#include <iomanip>
using namespace std;
typedef long long ll;
int main(){
  int n,m;
  cin >> n >> m;
  vector<int> count(n);
  for(int i = 0;i <= m - 1;i++){
    int a,b;
    cin >> a >> b;
    count[a - 1]++;
    count[b - 1]++;
  }
  bool yes = true;
  for(int i = 0;i <= n - 1;i++)if(count[i] % 2 != 0)yes = false;
  if(yes)cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}