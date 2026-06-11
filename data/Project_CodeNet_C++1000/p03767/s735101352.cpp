#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
  	cin>>N;
  vector<long long> a(3*N);
  for(long long &x: a) cin>>x; 
  sort(a.begin(),a.end());
  reverse(a.begin(),a.end());
  long long ans=0;
  for(int i=1;i<2*N;i+=2) ans+=a[i];
  cout<<ans<<endl;
}