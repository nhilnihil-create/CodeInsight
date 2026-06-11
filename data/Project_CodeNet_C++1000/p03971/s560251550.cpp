#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,A,B,a=0,b=1;
  string S;
  cin>>N>>A>>B>>S;
  for(char c:S)
    if(c=='c')
      cout<<"No"<<endl;
    else if(c=='a')
      if(a<A+B){
        cout<<"Yes"<<endl;
        a++;
      }else
        cout<<"No"<<endl;
    else{
      if(a<A+B && b<=B){
        cout<<"Yes"<<endl;
        a++;
      }else
        cout<<"No"<<endl;
      b++;
    }
}