#include <bits/stdc++.h>
using namespace std;


int main(){
  int64_t N,ans=1,x=0,y=0;
  cin >> N;
  vector<int64_t> A(N);
  for(int64_t i=0;i<N;i++){
    cin>>A.at(i);
    if(x==i){
      continue;
    }else if(y==0){
      if(A.at(i)>A.at(i-1)){
        y=1;
      }else if(A.at(i)<A.at(i-1)){
        y=2;
      }
    }else if(y==1){
      if(A.at(i)<A.at(i-1)){
        x=i;
        y=0;
        ans++;
      }
    }else{
      if(A.at(i)>A.at(i-1)){
        x=i;
        y=0;
        ans++;
      }
    }
  }
  cout << ans << endl;
  
}