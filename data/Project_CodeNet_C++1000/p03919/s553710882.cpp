#include<bits/stdc++.h>
using namespace std;
int main(){
  int h,w,y;cin>>h>>w;
  char x;
  vector<string> a(h*w);
  for(int i=0;i<h*w;i++)cin>>a.at(i);
  
  vector<char> cap(w);
  cap.at(0)='A';
  for(int g=1;g<w;g++)cap.at(g)=cap.at(g-1)+1;
  
  for(int j=0;j<h*w;j++){
    if(a.at(j)=="snuke"){
      x=cap.at(j%w);
      y=j/w+1;
      break;
    }
  }
  cout<<x<<y<<endl;
}