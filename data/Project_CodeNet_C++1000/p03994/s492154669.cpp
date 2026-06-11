#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin>>S;
  int K;
  cin>>K;
  int N=S.length();
  int C[N];
  for(int i=0;i<N;i++){
    C[i]=('z'-S.at(i)+1)%26;
    //cout<<i<<" "<<S.at(i)<<" "<<C[i]<<endl;
  }
  int temp=0;
  while(temp<N-1){
    if(C[temp]<=K){
      cout<<"a";
      K-=C[temp];
      temp++;
      continue;
    }
    cout<<S.at(temp);
    temp++;
  }
  K=K%26;
  if(S.at(N-1)+K >'z'){
    cout<<char(S.at(N-1)+K-26)<<endl;
  }
  else cout<<char(S.at(N-1)+K)<<endl;

  return 0;
}
