#include<bits/stdc++.h>
using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  vector<int>a(m*2);
  for(int i = 0; i<2*m; i++) cin >> a.at(i);
  vector<int>res(100);
  for(int i = 0; i<n; i++) res.at(i) = 0;
  for(int i = 0; i<2*m; i++){
    res.at(a.at(i))++;
  }
  for(int i = 1; i<=n; i++) cout << res.at(i) << endl;
}