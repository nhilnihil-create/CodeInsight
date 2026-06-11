#include<iostream>
using namespace std;
int main(){
  int n,l,r,s=0;
  cin>>n>>l>>r;
  for(int i=0;i<n;i++){
    s+=(r-l+1);
    cin>>l>>r;
  }
  cout<<s;
}