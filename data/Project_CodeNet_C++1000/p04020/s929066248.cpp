#include <bits/stdc++.h>
using namespace std;


int main() {
int N;
cin>>N;
vector<int> a(N);
for(int i=0;i<N;i++) cin>>a[i];

long ans=0;
for(int i=0;i<N-1;i++){
  ans+=a[i]/2;
  a[i]-=a[i]/2*2;
  int t=min(a[i],a[i+1]);
  ans+=t;
  a[i]-=t;
  a[i+1]-=t;
}
ans+=a[N-1]/2;
a[N-1]-=a[N-1]/2*2;
cout<<ans<<endl;
}
