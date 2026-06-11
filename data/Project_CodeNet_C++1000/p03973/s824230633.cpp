#include<bits/stdc++.h>
using namespace std;
#define int long long

int N;
signed main(){
  cin>>N;
  int k=1,ans=0;
  for(int i=0;i<N;i++){
    int A;
    cin>>A;
    if(k==1)ans+=A-1,k++;
    else if(A==k)k++;
    else if(A%k==0)ans+=A/k-1;
    else ans+=A/k;
  }
  cout<<ans<<endl;
}