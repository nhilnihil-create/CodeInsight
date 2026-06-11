#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;

int main(){
  int n;
  cin >> n;
  vector<int> ans;
  int sum = 0;
  for(int i = 1; i <= n; i++){
    if(sum < n) {
      ans.push_back(i);
      sum += i;
    } else {
      break;
    } 
  }
  int s = sum - n;
  for(auto x : ans) {
    if(x != s) cout << x << endl;
  }
  return 0;
}