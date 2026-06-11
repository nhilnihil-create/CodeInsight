#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  int n; cin >>n;
  int num[100005] = {0};
  rep(i,n){
    int a; cin >>a;
    num[a]++; num[a+1]++;
    num[a-1]++;
  }
  int ans = 0;
  rep(i,100005){
    ans = max(num[i], ans);
  }
  cout << ans << endl;
  return 0; 
}