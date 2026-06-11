#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c;
  cin >> a >> b >> c;
  bool ans=false;
  for(int i=0;i<1e7;i++){
    if(a*i%b==c){
      ans=true;
      break;
    }
  }
  cout << (ans?"YES":"NO") << endl;
}