#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  string S,T;
  cin>>N>>S>>T;
  int count=0;
  for(int i=0;i<N;i++){
    bool flag=true;
    for(int j=i;j<N;j++){
      if(S.at(j)!=T.at(j-i)){
        flag=false;
      }
    }
    if(flag){
      count=i;
      break;
    }
    if(i==N-1){
      count=N;
    }
  }
  cout<<N+count<<endl;
}
    