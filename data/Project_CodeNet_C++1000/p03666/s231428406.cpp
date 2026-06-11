#include <bits/stdc++.h>
using namespace std;

int main() {
  long int n,a,b,c,d,x,y;
  cin>>n>>a>>b>>c>>d;
  
  for(long int i=0;i<n;i++){
    x=(n-i-1)*(-1);
    y=i;
    if(x*d+y*c<=a-b && a-b<=x*c+y*d){
      cout<<"YES"<<endl;
      return 0;
    }
  }
  cout<<"NO"<<endl;
}