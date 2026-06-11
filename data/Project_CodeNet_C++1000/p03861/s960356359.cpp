#include<bits/stdc++.h>
using namespace std;

int64_t f(int64_t a, int64_t b){
  if(a==-1){
    return 0;
  }else{
    return a/b+1;
  }
}

int main(){
  int64_t a,b,x;
  cin>>a>>b>>x;
  cout<<f(b,x)-f(a-1,x)<<endl;
}
