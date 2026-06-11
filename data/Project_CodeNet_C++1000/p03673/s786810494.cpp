#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < n;i++)
using ll = long long;

int main() {
  int n; cin >>n;
  int a[212345];
  rep(i,n) cin >>a[i];
  int ans[512345];
  int left = 212345, right = left+1;
  rep(i,n){
    if(i%2==(n-1)%2) ans[left--]=a[i];
    else ans[right++]=a[i];
  }
  for(int i = left+1; i<right; i++){
    printf("%d ", ans[i]);
  }
  return 0;
}