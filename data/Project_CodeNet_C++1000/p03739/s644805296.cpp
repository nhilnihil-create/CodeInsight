#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>
using namespace std;

int n;

unsigned long long func(vector<long long int>& s, vector<int>& hugo, long long int k){
  unsigned long long int ret = 0;
  for(int i = 1; i < n; i++){
    if(s[i] == k){
      if(hugo[i - 1] == 0){
        hugo[i] = 1;
        ret++;
        k++;
      }
      else{
        hugo[i] = 0;
        ret++;
        k--;
      }
    }
    else if(s[i] > k){
      if(hugo[i - 1] == 0){
        hugo[i] = 1;
        ret += s[i] - k + 1;
        k += s[i] - k + 1;
      }
      else{
        hugo[i] = 0;
      }
    }
    else{
      if(hugo[i - 1] == 0){
        hugo[i] = 1;
      }
      else{
        hugo[i] = 0;
        ret += k - s[i] + 1;
        k -= k - s[i] + 1;
      }
    }
  }
  return ret;
}

void solve(){
  cin >> n;
  vector<long long int> v(n), sum(n), sum2(n);
  for(int i = 0; i < n; i++){
    cin >> v[i];
    if(i == 0) sum[i] = v[i];
    else sum[i] = sum[i - 1] + v[i];
  }
  vector<int> hugo(n), hugo2(n);
  sum2 = sum;
  unsigned long long int ans;
  long long int k = 0;

  if(sum[0] == 0){
    hugo[0] = 0;
    hugo2[0] = 1;
    ans = min(func(sum, hugo, -1), func(sum2, hugo2, 1)) + 1;
  }
  else if(sum[0] > 0){
    hugo[0] = 0;
    hugo2[0] = 1;
    ans = min(func(sum, hugo, 0), func(sum2, hugo2, sum2[0] + 1) + sum2[0] + 1);
  }
  else{
    hugo[0] = 1;
    hugo2[0] = 0;
    ans = min(func(sum, hugo, 0), func(sum2, hugo2, sum2[0] - 1) - sum2[0] + 1);
  }
  cout << ans << endl;
  return;
}

int main(){
  solve();
  return 0;
}
