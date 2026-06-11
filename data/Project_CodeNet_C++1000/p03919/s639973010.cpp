#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b;
  cin>>a>>b;
  char c;
  string d;
  for(int i=1;i<a+1;i++){
    for(int j=0;j<b;j++){
    cin>>d;
      if(d=="snuke"){
        c='A'+j;
      cout<<c<<i<<endl;
      }
    }
  }

}