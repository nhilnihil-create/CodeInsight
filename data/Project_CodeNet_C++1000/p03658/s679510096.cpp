#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,k; cin >> n >> k;
  int a[100];
  for(int i = 0; i<n;++i)cin >> a[i];
  sort(a,a+n);
  int sum = 0;
  for(int i = 0; i < k; ++i)sum += a[n-1-i];
  cout << sum << endl;
}