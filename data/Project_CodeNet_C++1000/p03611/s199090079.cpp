#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(100001);
  for(int i = 0; i < n; i++){
    cin >> a[i];
    b[a[i]]++;
  }
  long long ans = 0;
  for(int i = 0; i <= 100000; i++){
    long long tmp = 0;
    tmp += b[i-1] + b[i] + b[i+1];
    ans = max(tmp, ans);
  }
  cout << ans << endl;
}