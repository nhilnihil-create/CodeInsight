#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c;
  cin>>a>>b>>c;
  bool flag=false;
  for(int i=1;i<=b;i++){
    if((a*i%b)==c){
      flag=true;
      break;
    }
  }
  cout<<(flag?"YES":"NO")<<endl;
}
