#include<bits/stdc++.h>
using namespace std;
int main(){
  string S; cin>>S;
  int K=0;
  sort(S.begin(),S.end());
  for(int i=0; i<S.size()-1;i++){
    if(S.at(i)!=S.at(i+1))
      K++;
    else continue;
  }
  if(K==S.size()-1)
    cout<<"yes"<<endl;
  else cout<<"no"<<endl;
}
