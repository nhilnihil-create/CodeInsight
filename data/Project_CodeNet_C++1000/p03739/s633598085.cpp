#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  int n;
  cin >> n;
  ll A[n];
  for(int i=0; i<n; ++i) cin >> A[i];
  ll sum = 0, pm = 0, mp = 0;
  for(int i=0; i<n; ++i){
    sum += A[i];
    if(i%2 == 0 && sum <= 0){ pm += 1-sum; sum = 1; }
    if(i%2 != 0 && sum >= 0){ pm += 1+sum; sum = -1; }
  }
  sum = 0;
  for(int i=0; i<n; ++i){
    sum += A[i];
    if(i%2 == 0 && sum >= 0){ mp += 1+sum; sum = -1; }
    if(i%2 != 0 && sum <= 0){ mp += 1-sum; sum = 1; }
  }
  cout << min(pm, mp) << endl;
}