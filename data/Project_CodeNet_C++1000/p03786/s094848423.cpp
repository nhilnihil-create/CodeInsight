#include <bits/stdc++.h>
using namespace std;


int main() {
int N;
cin>>N;
vector<long> a(N);
for(int i=0;i<N;i++) cin>>a[i];
sort(a.begin(),a.end());
vector<long> b(N);
for(int i=0;i<N;i++){
  if(i==0)  b[0]=a[0];
  else b[i]=b[i-1]+a[i];
}
long ans=N;
long t=0;
for(int i=0;i<N-1;i++){
  if(b[i]*2>=a[i+1]) continue;
  else t=i+1;
}
cout<<ans-t<<endl;
}
