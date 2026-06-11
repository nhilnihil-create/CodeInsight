#include<bits/stdc++.h>
using namespace std;
int main(){
string O,E,D;
  cin>>O>>E;
  int N,M;
  N=O.size();
  M=E.size();
  for(int i=0;i<M;i++){
    D+=O.at(i);
    D+=E.at(i);
  }
  if(N!=M)
    D+=O.at(N-1);
    cout<<D<<endl;
}