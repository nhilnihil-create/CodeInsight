#include <bits/stdc++.h>
using namespace std;
int main(){
  int h,w;
  cin>>h>>w;
  string sn="snuke";
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      string s;
      cin>>s;
      if(s==sn){
        char c;
        cout<<(char)('A'+j)<<1+i;
        return 0;
      }
    }
  }
}
