#include<iostream>
#include<string>
using namespace std;
int main(){
  int a,b;cin>>a>>b;
  for(int i=0;i<a;i++){
    for(int j=0;j<b;j++){
      string str;cin>>str;
      if(str=="snuke"){
        cout<<(char)('A'+j)<<i+1<<endl;
      }
    }
  }
  return 0;
}