#include <bits/stdc++.h>
using namespace std;

int main() {
int a,b,c,s;
cin>>a>>b>>c;
s=-1*b+c;
if(b>=c){
  cout  <<  "delicious"  <<  endl;
}
else if(s<=a){
cout <<"safe"<<endl;
}
else cout <<"dangerous"<<endl;
}