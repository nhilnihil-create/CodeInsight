#include<bits/stdc++.h>
using namespace std;
int64_t g(int64_t a,int64_t b){
  if(a>b)
    return g(b,a);
  if(a==0)
    return b;
  return g(b%a,a);
}
int main(){
  int n;
  cin>>n;
  int64_t c=1;
  for(int i=0;i<n;i++){
    int64_t t;
    cin>>t;
    c*=t/g(t,c);
  }
  cout<<c<<endl;
}