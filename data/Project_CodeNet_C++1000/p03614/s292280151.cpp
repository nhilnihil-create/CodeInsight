#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N;
  cin>>N;
  int ans=0,cnt=0;
  for(int i=1;i<=N;i++){
    int a;
    cin>>a;
    if(a==i)cnt++;
    else ans+=(cnt+1)/2,cnt=0;
  }
  cout<<ans+(cnt+1)/2<<endl;
}