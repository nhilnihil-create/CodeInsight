#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;cin>>N;
  vector<long long>A(3*N);
  for(int i=0;i<3*N;i++){
    cin>>A.at(i);
  }
  sort(A.begin(),A.end());
  reverse(A.begin(),A.end());
  long long sum=0;
  int count=0;
  for(int i=0;i<3*N;i++){
    if(i%2==1){
      sum=sum+A.at(i);
      count++;
      A.at(3*N-count)=0;
    }
  }
  cout<<sum<<endl;
}