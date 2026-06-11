#include <bits/stdc++.h>
using namespace std;

int main() {
  string a,b;
  cin>>a>>b;
  int x,y;
  x=a.size();
  y=b.size();
  if(x>y) cout<<"GREATER"<<endl;
  else if(x<y) cout<<"LESS"<<endl;
  else{
    if(a>b) cout<<"GREATER"<<endl;
    else if(a<b) cout<<"LESS"<<endl;
    else cout<<"EQUAL"<<endl;
  }
}
