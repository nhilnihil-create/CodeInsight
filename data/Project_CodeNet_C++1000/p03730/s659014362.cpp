#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c;
  cin>>a>>b>>c;
  bool ans=false;
  
  for(int i=1;i<1000;i++){
    if((i*a%b)==(c%b)){
      ans = true;
      break;
    }
  }
  
  if(ans) cout << "YES" <<endl;
  else cout << "NO" << endl;
}