#include<bits/stdc++.h>
using namespace std;
int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  long long n,a[200005],sum=100000000000000000,s;
  a[0]=0;
  cin>>n;
  for(long long i=1;i<=n;i++){
    cin>>s;
    a[i]=a[i-1]+s;
  }
  long long nasu;
  for(long long i=1;i<n;i++){
    nasu=a[n]-a[i]*2;
    if(nasu<0) nasu*=-1;
    sum=min(sum,nasu);
  }
  cout<<sum<<'\n';
  return 0;
}
