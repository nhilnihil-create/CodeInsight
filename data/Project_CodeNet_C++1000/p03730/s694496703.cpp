#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c;
  cin>>a>>b>>c;
  string ans="NO";
  for(int i=1;i<=10000000;i++){
    if((a*i)%b==c){
      ans="YES";
      break;
    }
  }
  cout<<ans<<endl;
}
