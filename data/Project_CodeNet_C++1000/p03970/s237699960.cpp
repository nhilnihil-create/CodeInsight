#include<bits/stdc++.h>
using namespace std;

int main(void)
{ 
  char tur[]="CODEFESTIVAL2016";
  char s[16];
  int count=0;
  for(int i=0;i<16;i++){
    cin>>s[i];
    if(tur[i]!=s[i])
      count++;
  }
  cout<<count<<endl; 
}