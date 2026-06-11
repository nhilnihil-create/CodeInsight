#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n,c,k;
  cin>>n>>c>>k;
  vector<long long> t(n);
  for(long long &x: t) cin>>x;
  sort(t.begin(),t.end());
  long long count=0,memo=0;
  bool flag=false;
  for(long long i=0;i<n;){
    if(flag==false){
    if(i==n-1) {count++; break;}
    }
    long long m;
    m=min(n-1,i+c-1);
    if(flag){
      if(t[i]-t[memo]>k) {count++; flag=false; continue;}
      if(i==n-1) {count++; break;}
      if(t[i]-t[memo]<=k&&t[i+1]-t[memo]>k) {count++; flag=false;}
      i++;
      continue;
    }   
    if(t[m]-t[i]<=k) {count++; i+=m-i+1;}
    else  {flag=true; memo=i; i++;}
  }
  cout<<count<<endl;
}