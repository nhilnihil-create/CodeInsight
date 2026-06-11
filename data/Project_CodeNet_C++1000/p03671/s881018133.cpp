#include <bits/stdc++.h>
using namespace std;

int main() {
int a,b,c,n;
cin>>a>>b>>c;
n=min(a+b,a+c);
if(n<=b+c){
  cout  <<  n  <<  endl;
}
else cout <<b+c<<endl;
}