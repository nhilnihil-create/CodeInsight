#include<bits/stdc++.h>
using namespace std;
int main(){
  long long A,B,C;
  cin>>A>>B>>C;
  bool flag=true;
  long long count=0;
  while(flag){
    if(A%2!=0||B%2!=0||C%2!=0){
      flag=false;
      break;
    }
    if(A==B&&B==C){
      count=-1;
      flag=false;
      break;
    }
    long long AA=A;
    long long BB=B;
    long long CC=C;
    A=BB/2+CC/2;
    B=AA/2+CC/2;
    C=BB/2+AA/2;
    count++;
  }
  cout<<count<<endl;
}