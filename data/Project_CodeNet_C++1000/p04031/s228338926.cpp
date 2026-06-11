#include<bits/stdc++.h>
using namespace std;

int main(){

  int N, i, j;
  int mn=10000000;
  cin>>N;
  vector<int> a(N);
  
  for(i=0; i<N; i++) cin>>a[i];
  
  for(i=-100; i<=100; i++){
    int Sum=0;
    for(j=0; j<N; j++){
      Sum+=pow(i-a[j], 2);
    }
    mn=min(Sum, mn);
  }
  cout<<mn<<endl;
  return 0;
}