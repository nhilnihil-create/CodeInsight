#include <bits/stdc++.h>
using namespace std;


int main() {
long N;
cin>>N;
vector<long> a(100005);
long mod=1e9+7;

for(int i=0;i<N;i++) {
  int t;
  cin>>t;
  a[t]++;
}

if(N%2==1){
  if(a[0]!=1){
    cout<<0<<endl;
    return 0;
  }
  for(int i=2;i<=N-1;i+=2){
    if(a[i]!=2){
      cout<<0<<endl;
      return 0;
    }
  }
}

if(N%2==0){
  for(int i=1;i<=N-1;i+=2){
    if(a[i]!=2){
      cout<<0<<endl;
      return 0;
    }
  }
}

long ans=1;
for(int i=1;i<=N/2;i++){
  ans*=2;
  ans%=mod;
}
cout<<ans<<endl;


}
