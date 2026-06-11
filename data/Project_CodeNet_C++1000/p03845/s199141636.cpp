#include <bits/stdc++.h>

using namespace std;

int main(){

  int n;
  cin>>n;
  int a[n];
  int sum=0;
  for(int i=0; i<n; i++){
    cin>>a[i];
    sum+=a[i];
  }
  int m;
  cin>>m;

  for(int j=0; j<m; j++){
    int ans=sum;
    int p, x;
    cin>>p>>x;
    ans=sum-a[p-1]+x;
    cout<<ans<<endl;
  }
}
