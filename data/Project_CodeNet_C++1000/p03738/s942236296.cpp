#include <bits/stdc++.h>

using namespace std;

int main()
{
  string A,B; cin>>A>>B;
  int N=A.size(), M=B.size();
  if (N>M){
    cout<<"GREATER"<<endl;
  }else if(N<M){
    cout<<"LESS\n"<<endl;
  }else if(A>B){
 	cout<<"GREATER"<<endl;
  }else if(A<B){
    cout<<"LESS"<<endl;
  }else{
    cout<<"EQUAL"<<endl;
  }
  return 0;
}