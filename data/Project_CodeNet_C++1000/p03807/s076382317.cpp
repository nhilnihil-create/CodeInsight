#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  int n;
  cin >>n;
  int sum = 0;
  rep(i,n){
    int a;
    cin >>a;
    sum += a;
  }
  if(sum%2==0) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}