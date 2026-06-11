#include<bits/stdc++.h>
using namespace std;
int main(){
  string o,e;
  cin >> o >> e;
  int a=o.size(),b=e.size();
  for(int i=0;i<min(a,b);i++){
    cout << o[i] << e[i];
  }
  
  if(a>b) cout << o[a-1] << endl;
  else cout << endl;
  
}