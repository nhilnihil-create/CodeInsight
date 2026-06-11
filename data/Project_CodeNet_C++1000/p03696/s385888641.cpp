#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  string S;
  cin>>S;
  int L=0;
  int D=0;
  for(int i=0;i<N;i++){
    if(S.at(i)=='('){
      L++;
    }
    else L--;
    D=min(D,L);
  }
  for(int i=D;i<0;i++){
    cout<<"(";
  }
  cout<<S;
  for(int i=0;i<L-D;i++){
    cout<<")";
  }
  cout<<endl;
  return 0;
}
