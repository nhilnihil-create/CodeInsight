#include<bits/stdc++.h>
using namespace std;
int main(){
  int n; cin >> n;
  vector<int>a(n);
  for(int i = 0; i < n; i++){
    cin >> a.at(i);
  }
  int ans = 0;
  for(int i = 0; i < n; i++){
    int b = a.at(i) - 1;
    if(a.at(b) == i + 1) ans++;
  }
  cout << ans/2;
}