#include<bits/stdc++.h>
using namespace std;
int main(){
  string s1,s2,s3;
  cin >> s1 >> s2 >> s3;
  char dif;
  dif = 'A'-'a';
  printf("%c%c%c\n", s1[0] + dif, s2[0] + dif, s3[0] + dif);
}