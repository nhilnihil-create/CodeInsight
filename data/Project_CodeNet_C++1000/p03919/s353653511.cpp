#include <bits/stdc++.h>
using namespace std;
int main(){
  int h,w;
  cin >>h >>w;
  vector<vector<string>> a(h,vector<string>(w));
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin >>a[i][j];
      if(a[i][j]=="snuke"){
        printf("%c",'A'+j);
        cout<< i+1 <<endl;
      }
    }
  }
  
}