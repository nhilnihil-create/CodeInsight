#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long int

int main(){
int n;
cin>>n;
int a[n];
int average=0;
rep(i,n){
  cin>>a[i];
}
int ans=100000007;

for(int i=-1000;i<1000;i++){
int count=0;
rep(p,n){
  count+=abs(i-a[p])*abs(i-a[p]);
}
ans=min(ans,count);
}

cout<<ans<<endl;
  return 0;
}
