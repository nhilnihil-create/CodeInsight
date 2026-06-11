#include<bits/stdc++.h>
using namespace std;
int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  int a=0;
  string s,c="CODEFESTIVAL2016";
  cin>>s;
  for(int i=0;i<16;i++){
    if(s[i]!=c[i]){
      a++;
    }
  }
  cout<<a<<"\n";
}

  
