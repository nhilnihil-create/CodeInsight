#include<bits/stdc++.h>
using namespace std;

int main(){
  string S1,S2,S3;
  cin >> S1 >> S2 >> S3;
  cout << (char)('A' + (S1.at(0) - 'a')) << (char)('A' + (S2.at(0) - 'a')) << (char)('A' + (S3.at(0) - 'a')) << endl;
}
