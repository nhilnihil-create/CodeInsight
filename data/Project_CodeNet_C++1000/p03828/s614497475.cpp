#include <bits/stdc++.h>
using namespace std;
int INF=1e9+7;
int main(){
  int M;cin>>M;
  vector<int>A(M+1,1);
  for(int i=1;i<=M;i++){
    int s=i;
    for(int j=2;j<=M;j++){
      while(s%j==0){
        A[j]++;
        s/=j;
      }
    }
  }
  long long ans=1;
  for(int i=1;i<=M;i++){
    ans*=A[i];
    ans%=INF;
  }
  cout<<ans<<endl;
}