#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  long long i;
  for(i=0;i<12;i++){
      if(i==4)
      cout<<" "<<s[i];
      else
      cout<<s[i];
  }cout<<endl;
  return 0;
  
}
