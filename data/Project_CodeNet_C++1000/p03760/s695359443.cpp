#include<bits/stdc++.h>
using namespace std;
int main(){
  string S; string T;
  cin>>S>>T;
  int L=S.size(); int R=T.size();
  if(S.size()==T.size()){
  for(int i=0; i<L; i++){
    cout<<S.at(i)<<T.at(i);
  }
  }
  else{
    for(int i=0; i<R; i++){
      cout<<S.at(i)<<T.at(i);
    }
    cout<<S.at(S.size()-1);
  }
}
