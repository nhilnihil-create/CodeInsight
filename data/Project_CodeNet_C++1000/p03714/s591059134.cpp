#include <bits/stdc++.h>
using namespace std;

int main() {
  long n,a,zenhan=0,kohan=0,ans=-9999999999999999;
  cin >> n;
  priority_queue<long> a1;
  vector<long> a2(n);
  priority_queue<long> a3;
  vector<long> a1max(n+1);
  vector<long> a3min(n+1);
  for(long i=0;i<n;i++) {
    cin >> a;
    zenhan+=a;
    a1.push(0-a);
  }
  for(long i=0;i<n;i++) cin >> a2[i];
  for(long i=0;i<n;i++) {
    cin >> a;
    kohan+=a;
    a3.push(a);
  }
  a1max[0]=zenhan;
  a3min[0]=kohan;
  for(long i=0;i<n;i++) {
    a1.push(0-a2[i]);
    a=0-a1.top();
    a1.pop();
    zenhan+=a2[i]-a;
    a1max[i+1]=max(a1max[i],zenhan);
  }
  for(long i=0;i<n;i++) {
    a3.push(a2[n-i-1]);
    a=a3.top();
    a3.pop();
    kohan+=a2[n-i-1]-a;
    a3min[i+1]=min(a3min[i],kohan);
  }
  for(long i=0;i<=n;i++) {
    ans=max(ans,a1max[i]-a3min[n-i]);
  }

  cout << ans << endl;
}