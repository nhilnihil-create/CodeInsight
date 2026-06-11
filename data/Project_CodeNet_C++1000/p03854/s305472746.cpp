#include<bits/stdc++.h>
using namespace std;
int main(){
  string z,y="YES";
  cin>>z;
  int l=z.length();
  while(l>=5){
    if(z.substr(l-5)=="dream") z=z.substr(0,l-5);
    else if(l>=7&&z.substr(l-7)=="dreamer") z=z.substr(0,l-7);
    else if(z.substr(l-5)=="erase") z=z.substr(0,l-5);
    else if(l>=6&&z.substr(l-6)=="eraser") z=z.substr(0,l-6);
    else{y="NO"; break;}
    l=z.length();
  }
  if(l>0) cout<<"NO"<<endl;
  else cout<<y<<endl;
}