#include<bits/stdc++.h>
using namespace std;
int main(){
  int N=0,L=0;
  cin>>N >>L;
  vector<string>S(N);
  
  for (int i=0;i<N;i++){
    cin>>S[i];
  }
  sort(S.begin(),S.end());
  
  for (int j=0;j<N;j++){
    cout<<S[j];
  }
  
  return 0;
}