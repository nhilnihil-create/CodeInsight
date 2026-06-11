#include <bits/stdc++.h>
using namespace std;

int main(){
  int H,W;
  cin>>H>>W;
  for(int i=0;i<H;i++)
    for(int j=0;j<W;j++){
      string S;
      cin>>S;
      if(S=="snuke"){
        cout<<(char)('A'+j)<<i+1<<endl;
        return 0;
      }
    }
}