#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <climits>
#include <iomanip>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
int main(){
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  vector<int> inf(n);
  for(int i = 0;i < n;i++){
    if(s[i] == 'o')inf[i] = 1;
    else inf[i] = -1;
  }
  for(int i = 0;i < 2;i++){
    for(int j = 0;j < 2;j++){
      vector<int> now(n);
      if(i == 0)now[0] = 1;
      else now[0] = -1;
      if(j == 0)now[1] = 1;
      else now[1] = -1;
      if(now[0] * inf[0] == 1)now[n - 1] = now[1];
      else now[n - 1] = -1 * now[1];
      //cout << now[0] << " " << now[1] << " " << now[n - 1] << endl;
      for(int k = 1;k <= n - 3;k++){
        if(now[k] * inf[k] == 1)now[k + 1] = now[k - 1];
        else now[k + 1] = -1 * now[k - 1];
      }
      bool ok = true;
      if(now[n - 1] * inf[n - 1] == 1 && now[0] != now[n - 2])ok = false;
      if(now[n - 1] * inf[n - 1] == -1 && now[0] == now[n - 2])ok = false;
      if(now[n - 2] * inf[n - 2] == 1 && now[n - 1] != now[n - 3])ok = false;
      if(now[n - 2] * inf[n - 2] == -1 && now[n - 1] == now[n - 3])ok = false;
      if(ok){
        for(int k = 0;k < n;k++){
          if(now[k] == 1)cout << "S";
          else cout << "W";
        }
        cout << endl;
        return 0;
      }
    }
  }
  cout << -1 << endl;
}