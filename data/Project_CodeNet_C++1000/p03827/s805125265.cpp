#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
  int n;
  string s;
  cin>>n>>s;
  
  int x=0;
  int ans=0;
  
  for(int i=0;i<size(s)/sizeof(char);i++){
    if(s[i]=='I')x++;
    else x--;
    
    ans=max(ans,x);
  }
  cout<<ans<<endl;
  return 0;
}