#include<bits/stdc++.h>
using namespace std;
int main(){
  int n; cin >> n;
  vector<int>v(n,1<<30);
  int cnt = 0;
  for(int i = 0; i < n; ++i){
    cin >> v[i]; v[i]--;
    cnt += i == v[v[i]];
  }
  cout << cnt << endl;
}