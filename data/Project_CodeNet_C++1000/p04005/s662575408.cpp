#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<long long> n(3);
  cin >> n.at(0) >> n.at(1) >> n.at(2);
  
  sort(n.begin(), n.end());
  if(n.at(0)*n.at(1)%2 && n.at(2)%2) cout << n.at(0)*n.at(1) << endl;
  else cout << 0 << endl;
}