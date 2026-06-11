#include<iostream>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
int main(){
  int n,x;
  cin>>n>>x;
  int sz=2*n-1;
  if(x==1||x==sz)cout<<"No\n";
  else {
    cout<<"Yes\n";
    rep(i,sz)cout<<1+(n+x+i-1)%sz<<"\n";
    }
  return 0;
}
