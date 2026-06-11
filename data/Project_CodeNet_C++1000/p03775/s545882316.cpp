#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
  ll N;
  cin >> N;
  
  ll num = pow(N, 0.5);
  
  while (N % num != 0){
    num--;
  }
  
  num = N / num;
  
  int ans = 1;
  while (num < pow(10, ans - 1) || num >= pow(10, ans)){
    ans++;
  }
  
  cout << ans << endl;
}