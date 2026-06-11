#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin>>n;
  vector<int> a(n);
  for(int i=0; i<n; ++i)cin>>a[i];

  sort(a.begin(), a.end());

  int mul=0, now=a[0];
  for(int i=1; i<n; ++i){
    if(now==a[i])++mul;
    else now=a[i];
  }

  cout<<n-(mul+1)/2*2<<endl;
}
