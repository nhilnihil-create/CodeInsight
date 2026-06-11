#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<ll,ll> P;
#define M 1000000007
int main(){
  int n;
  cin>>n;
  vector<int> p(n),a(n),b(n);
  for(int i=0;i<n;i++){
    cin>>p[i];
    a[i]=i*n+1;
    cout<<a[i]<<" ";
  }cout<<endl;
  for(int i=0;i<n;i++){
    b[p[i]-1]=a[n-1]+1+i-a[p[i]-1];
  }
  for(int i=0;i<n;i++)cout<<b[i]<<" ";
}