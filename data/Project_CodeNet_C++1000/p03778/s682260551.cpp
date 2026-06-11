#include<bits/stdc++.h>
using namespace std;

int main(){
  long long w,a,b;
  cin>>w>>a>>b;
  if(a<=b&&b<=a+w){
    cout<<0<<endl;
  }
  else if(a>b&&a<=b+w){
    cout<<0<<endl;
  }
  else if(a<b&&b>a+w){
    cout<<b-a-w<<endl;
  }
  else if(a>b&&a>b+w){
    cout<<a-b-w<<endl;
  }
}
 
