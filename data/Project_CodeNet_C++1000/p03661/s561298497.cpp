#include <bits/stdc++.h>
using namespace std;
int main(){
  long long n,ans=1e15;
  cin >> n;
  long long a[n],sum=0,snuke=0;
  for(int i=0;i<n;i++){
    cin >> a[i];
    sum+=a[i];
  }
  for(int i=0;i<n-1;i++){
    snuke+=a[i];
    ans=min(ans, abs(sum-snuke-snuke));
  }
  cout << ans << endl;
  return 0;
}
