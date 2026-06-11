#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<long long> A(3);
  cin >> A.at(0) >> A.at(1) >> A.at(2);
  
  sort(A.begin(),A.end());
  
  if(A.at(0)%2==0||A.at(1)%2==0||A.at(2)%2==0){cout << 0 << endl;}
  else {cout << A.at(0)*A.at(1) << endl;}
    
}