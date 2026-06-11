#include <bits/stdc++.h>
using namespace std;
int main() {
  int a,b,c; cin>>a>>b>>c;
  bool ans=false;
  for(int i=1; i<=b; i++){
    if(a*i%b==c){
      ans=true;
      break;
    }
  }
  cout<<(ans?"YES":"NO");
}