#include<bits/stdc++.h>
using namespace std;
int main(){
  char s[17],t[17];
  int a=0;
  cin >> s;
  strcpy(t,"CODEFESTIVAL2016");
  for(int i=0;i<16;i++){
    if(s[i]!=t[i])a++;
  }
  cout << a;
}
