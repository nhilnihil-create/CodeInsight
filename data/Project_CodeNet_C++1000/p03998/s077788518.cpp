#include<iostream>
#include<string>
using namespace std;
int main(){
string a,b,c;
  cin>>a>>b>>c;
  char t='a';
  
  while(1){
    if(t=='a'&&a.empty()){
      cout<<"A"<<endl;
      return 0;
    }
    else if(t=='b'&&b.empty()){
      cout<<"B"<<endl;
      return 0;
    }
    else if(t=='c'&&c.empty()){
      cout<<"C"<<endl;
      return 0;
    }
    
    if(t=='a'){
      t=a[0];
      a.erase(a.begin());
    }
    else if(t=='b'){
      t=b[0];
      b.erase(b.begin());
    }
    else if(t=='c'){
        t=c[0];
      c.erase(c.begin());
    }
  }
  return  0;
}
