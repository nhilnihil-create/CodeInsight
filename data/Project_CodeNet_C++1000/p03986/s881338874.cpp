#include<bits/stdc++.h>
using namespace std;
int main(){
  string S;
  cin>>S;
  int t=0,ma=0;
  for(char c:S){
    if(c=='T')
      t++;
    else
      t--;
    ma=max(t,ma);
  }
  cout<<ma*2<<endl;
}