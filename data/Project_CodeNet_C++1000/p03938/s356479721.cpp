#include <bits/stdc++.h>
using namespace std;

signed main(){
  int n;cin>>n;
  vector<int> p(n);
  for(int i=0;i<n;i++){cin>>p[i];p[i]--;}
  vector<int> a(n),b(n);
  for(int i=0;i<n;i++)a[i]=(i+1)*30000;
  for(int i=0;i<n;i++)b[n-1-i]=(i+1)*30000;
  for(int i=0;i<n;i++)a[p[i]]+=i;
  for(int i=0;i<n;i++)cout<<a[i]<<" ";cout<<endl;
  for(int i=0;i<n;i++)cout<<b[i]<<" ";cout<<endl;
}
