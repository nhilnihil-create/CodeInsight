#include<bits/stdc++.h>
using namespace std;

int main(){
  int A,B,C;cin>>A>>B>>C;
  int count=0;
  bool can=false;
  for(int i=0;i<101;i++){
    count+=A;
    if(count%B==C) can=true;
  }
  cout<<(can?"YES":"NO")<<endl;
}
