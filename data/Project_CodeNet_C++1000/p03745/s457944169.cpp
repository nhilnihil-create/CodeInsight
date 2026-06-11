#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  int n;
  cin >> n;
  ll A[n];
  for(int i=0; i<n; ++i) cin >> A[i];
  int ans = 0;
  for(int i=0; i<n; ++i){
    while(i+1 < n && A[i] == A[i+1]) ++i;
    if(i+1 < n && A[i] < A[i+1]){
      while(i+1 < n && A[i] <= A[i+1]) ++i;
    }
    else if(i+1 < n && A[i] > A[i+1]){
      while(i+1 < n && A[i] >= A[i+1]) ++i;
    }
    ++ans;
  }
  cout << ans << endl;
}