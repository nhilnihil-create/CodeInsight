#include <bits/stdc++.h>
using namespace std;


int main() {

int N;
cin>>N;
vector<int> a(N);
for(int i=0;i<N;i++) cin>>a[i];

long ans=1e18;
for(int i=-100;i<=100;i++){
  long tmp=0;
  for(int j=0;j<N;j++){
    tmp+=(i-a[j])*(i-a[j]);
  }
  ans=min(tmp,ans);
}
cout<<ans<<endl;
}
