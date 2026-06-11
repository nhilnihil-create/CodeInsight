#include<iostream>
using namespace std;

int main(){
  int n,a,b;cin>>n>>a>>b;
  int x[n];
  for(int i=0;i<n;i++) cin>>x[i];
  long long ans=0;
  for(int i=1;i<n;i++){
    ans+=min((long long)a*(long long)(x[i]-x[i-1]),(long long)b);
  }
  cout<<ans<<endl;
  return 0;
}