#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int64_t>N(3);
  cin >> N.at(0) >> N.at(1) >> N.at(2);
  sort(N.begin(), N.end());
  
  if(N.at(0)%2!=0 && N.at(1)%2!=0 && N.at(2)%2!=0){
    cout << N.at(0)*N.at(1) << endl;
  }
  else cout << 0 << endl;
  
}