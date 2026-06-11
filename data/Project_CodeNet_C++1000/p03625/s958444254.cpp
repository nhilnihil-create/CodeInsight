#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  vector<long long>A(N);
  for(int i=0;i<N;i++){
    cin>>A.at(i);
  }
  sort(A.begin(),A.end());
  reverse(A.begin(),A.end());
  vector<long long>Ans;
  long long mark=-1;
  long long cnt=0;
  for(int i=0;i<N;i++){
    if(mark==A.at(i)){
      cnt++;
      if(cnt==2){
        Ans.push_back(A.at(i));
        cnt=0;
      }
    }
    else{
      cnt=1;
      mark=A.at(i);
    }
  }
  if(Ans.size()<2){
    cout<<0<<endl;
  }
  else{
    cout<<Ans.at(0)*Ans.at(1)<<endl;
  }
}
    
    