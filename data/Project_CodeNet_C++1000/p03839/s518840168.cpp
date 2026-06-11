#include <bits/stdc++.h>
using namespace std;
long long s[100009],t[100009];

int main(){
  long long N,K;
  cin >> N >> K;
  vector<long long> a(N);
  for(int i=0;i<N;i++)cin >> a[i];
  long long sum=0,q=100000000000000000,r=0,z=0;
  for(int i=0;i<N;i++){if(a[i]>0)sum+=a[i];}
  for(int i=0;i<N;i++){s[i+1]+=s[i]+a[i]; t[i+1]+=t[i]+max(a[i],z);}
  for(int i=0;i+K<=N;i++){
    long long x=t[i+K]-t[i],c=s[i+K]-s[i];
    if(x-max(c,z)<q){q=x-max(c,z);}
  }
  cout << sum-q << endl;
}