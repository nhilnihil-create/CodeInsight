#include <bits/stdc++.h>
using namespace std;

int main() {
int a,b,c,s,t;
cin>>a>>b>>c;
s=max(a,b)-min(a,b);
t=max(a,c)-min(a,c);
if(s>=t){
  cout  <<  "B"  <<  endl;
}
else{
cout <<"A"<<endl;
}
}