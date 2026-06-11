#include <bits/stdc++.h> 

using namespace std; 

int main(){ 
  string s;
  cin>>s;
  int a=s.size();
  for(int i=0;i<(a+1)/2;i++){
    cout<<s[2*i];
  }
}