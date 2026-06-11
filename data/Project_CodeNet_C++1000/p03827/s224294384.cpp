#include<iostream>
#include<string>
using namespace std;
int main(){
  string s;
  int a;
  while(cin>>a){
    cin>>s;
  	int x=0,ans=0;
    for(int i=0;i<a;i++){
      if(s[i]=='I') x++;
      else x--;
      ans=max(ans,x);	
    }
    cout<<ans<<endl;
  }
  return 0;
}