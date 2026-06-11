#include<bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n,k;
  cin>>n>>k;
  string a[n];
  string b;
  for(int i=0;i<n;i++)
  {
      cin>>b;
      a[i]=b;
  }
  sort(a,a+n);
  for(int i=0;i<n;i++)
  cout<<a[i];
}
