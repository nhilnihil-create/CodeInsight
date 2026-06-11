#include <iostream>
using namespace std;

int min(int x,int y){
  if(x<y) return x;
  return y;
}

int main(){
  int a,b,c;
  cin>>a>>b>>c;
  int ans=100000000;
  ans=min(ans,a+b);
  ans=min(ans,b+c);
  ans=min(ans,a+c);
  cout<<ans<<endl;
  return 0;
}