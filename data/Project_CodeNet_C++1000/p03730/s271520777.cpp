#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  int a,b,c;
  cin>>a>>b>>c;
  bool ans=0;
  rep(i,100100100){
    if(a*i%b==c){
      ans=1;
    }
  }
  if(ans){
    cout<<"YES"<<endl;
  }else{
    cout<<"NO"<<endl;
  }
}