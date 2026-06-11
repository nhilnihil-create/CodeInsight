#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD= 1000000007;
signed main() {
int n;
cin>>n;
int c[100]={},a,amax=0;
for(int i=0;i<n;i++){
  cin>>a;
  c[a]++;
  amax=max(amax,a);
}
if(amax%2){
  if(c[(amax+1)/2]!=2){
    cout<<"Impossible";
    return 0;
  }
  for(int i=(amax+1)/2+1;i<=amax;i++){
    if(c[i]<2){
      cout<<"Impossible";
      return 0;
    }
  }
  cout<<"Possible";
  return 0;
}else{
  if(c[(amax)/2]!=1){
    cout<<"Impossible";
    return 0;
  }
  for(int i=(amax)/2+1;i<=amax;i++){
    if(c[i]<2){
      cout<<"Impossible";
      return 0;
    }
  }
  cout<<"Possible";
  return 0;
}
return 0;

}
