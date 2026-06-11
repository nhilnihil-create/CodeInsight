#include <bits/stdc++.h>
using namespace std;

const long long MOD=pow(10,9)+7;
int main(){
  int N;cin>>N;
  long long ans=1;
  for(int i=0;i<N;i++){
    ans*=i+1;
    ans%=MOD;
  }
  cout <<ans<<endl;
}