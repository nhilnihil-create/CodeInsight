#include <bits/stdc++.h>
using namespace std;
long long n,i,c,a[300000];
bool res=true;
int main(){
  for(cin>>n;i<n*3;i++)cin>>a[i];
  sort(a,a+3*n,greater<int>());
  for(i=0;i<n;i++){
    c+=a[1+i*2];
  }
  cout<<c;
}