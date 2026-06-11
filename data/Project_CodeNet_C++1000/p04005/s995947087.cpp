#include<bits/stdc++.h>
using namespace std;

int main() {
  vector<long long> vec(3);
  long long tmpA,tmpB;

  cin >> vec.at(0) >> vec.at(1) >> vec.at(2);
  sort(vec.begin(), vec.end());
  
  tmpA = vec.at(0) * vec.at(1) * (vec.at(2) / 2);
  tmpB = vec.at(0) * vec.at(1) * (vec.at(2) - vec.at(2) / 2);
  
  cout << abs(tmpB - tmpA);
}
