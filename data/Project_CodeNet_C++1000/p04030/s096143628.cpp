#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
const int MOD = 1e9+7;
using ll = long long;
using vi = vector<int>;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ALL(x) x.begin(), x.end()
int main() {
  string a;
  cin >> a;
  int b = a.size();
  int ans[111];
  int sum = 0,tmp=0;
  for(int i = b-1;i>=0;i--){
    if(a.at(i)=='B')sum++;
    else if(sum==0){
      ans[tmp] =  a.at(i)-'0';
      tmp++;
    }
    else sum=max(0,sum-1);
  }
  for(int i = tmp-1;i>=0;i--){
    cout << ans[i];
  }
}