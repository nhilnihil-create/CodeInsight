#include<bits/stdc++.h>
using namespace std;
int main(){
  queue<char>A;queue<char>B;queue<char>C;
  string a,b,c; cin>>a>>b>>c;
  for(int i=0;i<a.size();i++)A.push(a.at(i));
  for(int i=0;i<b.size();i++)B.push(b.at(i));
  for(int i=0;i<c.size();i++)C.push(c.at(i));
  int count=0;
  for(int i=0;i<500;i++){
    if(count==0){
      if(A.empty()){cout<<"A"<<endl;return 0;}
      count=A.front()-97;
      A.pop();
    }
    else if(count==1){
      if(B.empty()){cout<<"B"<<endl;return 0;}
      count=B.front()-97;
      B.pop();
    }
    else{
      if(C.empty()){cout<<"C"<<endl;return 0;}
      count=C.front()-97;
      C.pop();
    }
  }
}