#include<bits/stdc++.h>
using namespace std;
int main(){
  int n; cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++){
    cin >> a[i];
    a[i]--;
  }
  int cnt = 0;
  for(int i = 0; i < n; i++){
    int j = a[i];
    if(a[j] == i) cnt++;
  }
  cout << cnt/2 << endl;
  return 0;
}