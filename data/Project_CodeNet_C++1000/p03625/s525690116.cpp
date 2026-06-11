#include<bits/stdc++.h>
using namespace std;
int main(){
int N;
  cin>>N;
  vector<int64_t>A(N);
  for(int i=0;i<N;i++){
  cin>>A.at(i);
  }sort(A.begin(),A.end());
  reverse(A.begin(),A.end());
  int64_t a=0; 
  int64_t b=0;
  int sum=-1;
  for(int i=0;i<N-3;i++){
  if(A.at(i)==A.at(i+1)){
  a=A.at(i); sum=i+2;break;
  }
  }if(sum!=-1){
  for(int j=sum;j<N-1;j++)
    if(A.at(j)==A.at(j+1)){
    b=A.at(j); break;
    }
  } int64_t ans=a*b;
  cout<<ans<<endl;

    return 0;
}