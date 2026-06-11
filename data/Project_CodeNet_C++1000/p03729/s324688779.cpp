#include <bits/stdc++.h>
using namespace std;

int main() {
string a,b,c;
cin>>a>>b>>c;
int A,B;
A=a.size();
B=b.size();
char w,x,y,z;
w=a.at(A-1);
x=b.at(0);
y=b.at(B-1);
z=c.at(0);
if(w==x&&y==z){
  cout  <<  "YES"  <<  endl;
}
else cout <<"NO"<<endl;
}