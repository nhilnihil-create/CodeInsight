#include <bits/stdc++.h>
using ll = long long;
using namespace std;
ll mod=1e9;

int main(){
  ll n;
  cin>>n;
  int sum(0);
  int tmp(0);
  for (int i(1);i<=n;i++){
    sum+=i;
    if (sum>=n){
      tmp=i;
      break;
    }
  }
  for (int i(1);i<=n;i++){
    if (i==sum-n) continue;  
    else if(tmp<i) break;
    else {
      cout << i << endl;
    }
  }
  return 0;
}
