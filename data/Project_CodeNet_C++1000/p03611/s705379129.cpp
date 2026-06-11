#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  int n;
  cin >>n;
  int num[100100] = {0};
  int M = 0;
  rep(i,n){
    int a; cin >>a;
    a++;
    num[a-1]++; num[a]++;
    num[a+1]++;
    if(a+1>M) M = a+1;
  }
  int ans = 0;
  rep(i,M){
    if(num[i]>ans) ans = num[i];
  }
  cout << ans << endl;
  return 0;
}
