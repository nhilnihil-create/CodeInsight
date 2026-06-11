#include "bits/stdc++.h"

using namespace std;

const int MOD=1000000007;

int main(){
  int N;
  cin>>N;
  vector<int>v(N);
  for(int i=0;i<N;i++)cin>>v[i];
  long long int ans=1;
  int index =0;
  for(int i=0;i<N;i++){
    while(index+1<N&&(v[index]+1)/2>index-i)index++;
    ans*=index+1-i;
    ans%=MOD;
  }
  cout<<ans<<endl;
}