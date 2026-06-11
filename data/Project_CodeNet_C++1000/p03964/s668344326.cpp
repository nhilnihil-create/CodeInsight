#include <bits/stdc++.h>
using namespace std;

int main() {
  long n;
  cin >> n;
  vector<long> t(n),a(n),x(n),y(n);
  for(long i=0;i<n;i++) cin >> t[i] >> a[i];
  x[0]=t[0],y[0]=a[0];
  for(long i=1;i<n;i++) {
    x[i]=((x[i-1]-1)/t[i]+1)*t[i];
    y[i]=((y[i-1]-1)/a[i]+1)*a[i];
    if(x[i]/t[i]<y[i]/a[i]) x[i]=y[i]/a[i]*t[i];
    else y[i]=x[i]/t[i]*a[i];
  }
  cout << x[n-1]+y[n-1] << endl;
}