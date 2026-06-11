#include<bits/stdc++.h>
using namespace std;

int f(int64_t a, int64_t b){
  if(a==-1){return 0;}else{return a/b+1;}
}

int main(){
  int64_t a,b,x,cnt;
  cin>>a>>b>>x;
  if(a==0){cnt=b/x+1;}
  else{cnt=b/x-(a-1)/x;}
  cout<<cnt<<endl;
}
