#include <bits/stdc++.h>
using namespace std;
 
int main(){
  string s1,s2,s3;
  cin >> s1 >> s2 >> s3;
  char S1,S2,S3;
  S1=s1.at(0);
  S2=s2.at(0);
  S3=s3.at(0);
  
  S1-='a'-'A';
  S2-='a'-'A';
  S3-='a'-'A';
  
  cout << S1 << S2 << S3 << endl;
}