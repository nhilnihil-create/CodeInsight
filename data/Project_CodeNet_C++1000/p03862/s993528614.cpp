#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,x;
  cin >> n >> x;
  vector<int> a(n);
  long long ans=0;
  for(int i=0;i<n;i++){
    cin >> a[i];
    if(x<a[i]){
      ans+=a[i]-x;
      a[i]=x;
    }
  }
  for(int i=1;i<n;i++){
    if(x<a[i-1]+a[i]){
      ans+=a[i-1]+a[i]-x;
      a[i]=x-a[i-1];
    }
  }
  cout << ans << endl;
}