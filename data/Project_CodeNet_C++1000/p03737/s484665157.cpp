#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string S1,S2,S3;
  cin >> S1 >> S2 >> S3;
  
  S1[0] += 'A'-'a';
  S2[0] += 'A'-'a';
  S3[0] += 'A'-'a';
  
  cout << S1.at(0) << S2.at(0) << S3.at(0) << endl;
}