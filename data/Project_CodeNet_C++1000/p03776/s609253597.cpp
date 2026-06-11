#include <bits/stdc++.h>
using namespace std;

long ncr(long n,long r) {
  long re=1;
  for(long i=1;i<=r;i++) {
    re*=n-i+1;
    re/=i;
  }
  return re;
}

int main() {
  long double n,a,b,ans1=0,ans2=0;
  cin >> n >> a >> b;
  vector<long double> v(n);
  map<long double,long double> aaa;
  for(long i=0;i<n;i++) {
    cin >> v[i];
    aaa[v[i]]++;
  }

  sort(v.begin(),v.end());
  reverse(v.begin(),v.end());
  for(long i=0;i<a;i++) ans1+=v[i];
  ans1/=a;
  if(aaa[v[0]]>a) {
    for(long i=a;i<=min(b,aaa[v[0]]);i++) ans2+=ncr(aaa[v[0]],i);
  } else {
    for(long i=0;true;i++) {
      if(v[i]==v[a-1]) {
        ans2=ncr(aaa[v[a-1]],a-i);
        break;
      }
    }
  }
  cout << fixed << setprecision(10);
  cout << ans1 << endl;
  cout << fixed << setprecision(0);
  cout << ans2 << endl;
}