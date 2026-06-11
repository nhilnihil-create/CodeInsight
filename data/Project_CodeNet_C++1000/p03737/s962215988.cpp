#include<bits/stdc++.h>
using namespace std;

int main(){
  string S1,S2,S3;
  cin >> S1 >> S2 >> S3;
  transform(S1.begin(),S1.end(),S1.begin(), ::toupper);
  transform(S2.begin(),S2.end(),S2.begin(), ::toupper);
  transform(S3.begin(),S3.end(),S3.begin(), ::toupper);
  
  cout << S1.at(0) << S2.at(0) << S3.at(0) << endl;
}