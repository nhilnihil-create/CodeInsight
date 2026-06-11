#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<long>p(n);
  int i;
  for(i=0;i<n;i++)cin>>p[i];
  vector<long>a(n);
  vector<long>b(n);
  a[0]=1;
  b[0]=1e9-50000;
  for(i=1;i<n;i++){
    a[i] = a[i-1]+30000;
    b[i] = b[i-1]-30000;
  }
  for(i=1;i<n;i++){
    a[p[i]-1]+=i;
  }
  for(i=0;i<n-1;i++){
    cout << a[i] << " ";
  }
  cout<<a[n-1]<<endl;
  for(i=0;i<n-1;i++){
    cout<<b[i]<<" ";
  }
  cout<<b[n-1]<<endl;
}
