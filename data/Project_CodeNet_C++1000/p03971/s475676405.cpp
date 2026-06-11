#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,A,B;
  cin>>N>>A>>B;
  string S;
  cin>>S;
  int count_jp=0,count_al=0;
  vector<string> ans(N,"No");
  for(int i=0;i<N;i++){
    if(S.at(i)=='a' && count_jp+count_al<A+B){
      ans.at(i)="Yes";
      count_jp++;
    }
    else if(S.at(i)=='b' && count_jp+count_al<A+B && count_al<B){
      ans.at(i)="Yes";
      count_al++;
    }
  }  
  for(int i=0;i<N;i++){
  cout<<ans.at(i)<<endl;
  }
}