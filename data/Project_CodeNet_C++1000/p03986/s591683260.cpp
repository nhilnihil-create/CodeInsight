#include<bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin>>S;
  int N=S.size();
  int counts=0;
  int countt=0;
  for(int i=0;i<N;i++){
    if(S[i]=='S')counts++;
    else if(counts>0)counts--;
    else countt++;
  }
  cout<<counts+countt<<endl;
}