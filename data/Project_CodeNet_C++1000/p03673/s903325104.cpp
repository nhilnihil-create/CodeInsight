#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
  int n;
  cin >> n;
  vector<ll> a(n),b(n),c(n);
  for(ll & e:c)cin>>e;
  for(int i=0;i<n;i++){
    if(i%2==0){
      a[i/2]=c[i];
    }
    else{
      b[i/2+1]=c[i];
    }
  }
  if(n%2==0){
    for(int i=1;i<=n/2;i++){
      cout<<b[n/2-i+1]<< ' ';
    }
    for(int i=0;i<n/2;i++){
      cout<<a[i] << ' ';
    }  
  }
  else{
    for(int i=0;i<=n/2;i++){
      cout<<a[n/2-i]<<' ';
    }
    for(int i=1;i<=n/2;i++){
      cout << b[i]<< ' ';
    }  
  }
cout << endl;
      return 0;
}
