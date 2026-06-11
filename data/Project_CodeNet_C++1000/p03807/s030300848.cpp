#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> vec(n);
  for(int i = 0;i < n;i++) cin >> vec.at(i);
  int cout_odd = 0;
  for(auto x: vec) if(x % 2 == 1 ) cout_odd++;
  if(cout_odd % 2 == 0) cout << "YES" << endl;
  else cout << "NO" << endl;
}