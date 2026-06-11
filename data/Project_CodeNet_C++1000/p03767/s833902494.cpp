#include <bits/stdc++.h>
using namespace std;
#define	rep(i,n)	for(long long i=0;i<n;i++)
int main(){
  long long n;	cin >> n;
  vector<long long>	a(3*n);
  rep(i,3*n)	cin >> a[i];
  sort(a.begin(),a.end());
  long long sum=0;
  for(long long i=n;i<3*n;i+=2){
    sum+=a[i];
  }
  cout << sum;
}