#include<bits/stdc++.h>
using namespace std;

int main(){
  string a,b,c;
  cin>>a>>b>>c;
  if(a[0]>='a'&&a[0]<='z'){
    a[0]+='A'-'a';
  }
  if(b[0]>='a'&&b[0]<='z'){
    b[0]+='A'-'a';
  }
  if(c[0]>='a'&&c[0]<='z'){
    c[0]+='A'-'a';
  }
  cout<<a[0]<<b[0]<<c[0]<<endl;
}