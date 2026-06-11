#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,M,sum=0;
  cin>>N;
  vector<int> A(N);
  for(int &i:A){
    cin>>i;
    sum+=i;
  }
  cin>>M;
  while(M--){
    int P,X;
    cin>>P>>X;
    cout<<sum-A[P-1]+X<<endl;
  }
}