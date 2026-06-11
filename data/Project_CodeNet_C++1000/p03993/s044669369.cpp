#include <bits/stdc++.h>
using namespace std;
long long n,i,b,c;
int main(){
  cin>>n;
  vector<long long> a(n,0);
  for(;i<n;i++)cin>>b,b--,a[i]=b;
  for(i=0;i<n;i++){
    if(a[a[i]]==i)c++;
  }
  cout<<c/2;
}