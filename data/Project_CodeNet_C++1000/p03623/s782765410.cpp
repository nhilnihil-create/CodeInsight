#include<iostream>
using namespace std;

int abs(int x){
  return (x<0 ? -x : x);
}

int main(){
  int x,a,b;
  cin>>x>>a>>b;
  cout<<(abs(a-x)<abs(b-x)?"A":"B")<<endl;
  return 0;
}
