#include <iostream>

using namespace std;

int main(){
  int a,b,c;
  cin>>a>>b>>c;
  int ans=3;
  if(a==b) ans--;
  if(b==c) ans--;
  if(a==c) ans--;
  cout<<max(1,ans)<<endl;
  return 0;

}