#include<bits/stdc++.h>
using namespace std;

int main(){
  int h,w;
  cin>>h>>w;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      string s;
      cin>>s;
      if(s=="snuke"){
        char ans=j+65;
        cout<<ans<<i+1<<endl;
        return 0;
      }
    }
  }
}