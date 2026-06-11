#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
  ll ans=0,n;
  string a;
  cin>>a;
  n=a.length();
  for(int i=0;i<n-1;i++){
    if(a[i]!=a[i+1]){
      ans++;
    }
  }
  cout<<ans<<endl;
  return 0;
}