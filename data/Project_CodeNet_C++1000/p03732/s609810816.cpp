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
  ll n,w;
  cin >> n >> w;
  vector<vector<ll>> a(4);
  ll base = 0;
  for(int i = 0;i < n;i++){
    ll inv,inw;
    cin >> inw >> inv;
    if(i == 0){
      a[0].push_back(inv);
      base = inw;
    }
    else{
      a[inw - base].push_back(inv);
    }
  }
  ll res = 0;
  for(int i = 0;i < 4;i++)sort(a[i].rbegin(),a[i].rend());
  for(int i = 0;i <= a[0].size();i++){
    for(int j = 0;j <= a[1].size();j++){
      for(int k = 0;k <= a[2].size();k++){
        for(int l = 0;l <= a[3].size();l++){
          ll noww = base * i + (base+1) * j + (base+2) * k + (base+3) * l;
          if(noww > w)continue;
          ll nowv = 0;
          for(int m = 0;m < i;m++)nowv += a[0][m];
          for(int m = 0;m < j;m++)nowv += a[1][m];
          for(int m = 0;m < k;m++)nowv += a[2][m];
          for(int m = 0;m < l;m++)nowv += a[3][m];
          res = max(res,nowv);
        }
      }
    }
  }
  cout << res << endl;
}