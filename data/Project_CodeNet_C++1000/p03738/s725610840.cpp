#include <bits/stdc++.h>
using namespace std;

int main(){
  string A,B;
  cin>>A>>B;
  if(A.size()!=B.size()){
    if(A.size()>B.size())
      cout<<"GREATER"<<endl;
    else
      cout<<"LESS"<<endl;
    return 0;
  }
  for(int i=0;i<A.size();i++)
    if(A[i]!=B[i]){
      if(A[i]>B[i])
        cout<<"GREATER"<<endl;
      else
        cout<<"LESS"<<endl;
      return 0;
    }
  cout<<"EQUAL"<<endl;
}