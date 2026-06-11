#include <bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
map<long long, long long> b;
int a[100010];
int main(){
  long long n;
  while(cin>>n){
    b.clear();
    int tmp=0, lst=0, past=0;
    for(int i=0; i<n; ++i){
      scanf("%d",&a[i]);
      if(i==0){
        ++b[0];
      }
      else{
        ++b[max(past, (i-tmp)/2)];
        past=max(past, (i-tmp)/2);
      }
      tmp+=a[i]-lst-1;
      lst=a[i];
    }
    long long ans=b[0], sm=b[0];
    for(int i=1; i<n; ++i){
      sm+=b[i]-1;
      sm%=mod;
      ans*=sm;
      ans%=mod;
    }
    cout<<ans<<endl;
  }
  return 0;
}


