#include <bits/stdc++.h>
using namespace std;
int main() {
  long long A,B,C;
  cin >> A >> B >> C;
  
  if (A%2==0 || B%2==0 || C%2==0){
    cout << 0 << endl;
  }
  else {
    vector<long long>D(3);
    D.at(0) = A;
    D.at(1) = B;
    D.at(2) = C;
    sort(D.begin(), D.end());
    long long E = D.at(0)*D.at(1);
    cout << E << endl;
  }
}