#include <bits/stdc++.h>
using namespace std;
int main(){
  long long int N;
  long long int sum=0;
  cin>>N;
  long long int L[2*N];
 if(N>=1&&N<=100){
  for(int i=0;i<2*N;i++){
      cin>>L[i];
  }
  int S = sizeof(L)/sizeof(L[0]); 
  sort(L, L+S, greater<int>()); 
 
  for(int i=0;i<2*N;i++){
      if(i%2==0){
          sum+=min(L[i],L[i+1]);
      }
  }
  cout<<sum;
 }
    return 0;
}