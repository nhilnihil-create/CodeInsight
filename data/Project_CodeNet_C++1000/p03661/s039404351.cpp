#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

int main(){
  int n;
  cin >> n;
  vector<LL> a(n);
  LL total=0;
  for(int i=0;i<n;i++){
    cin >> a[i];
    total+=a[i];
  }
  LL ans=2000000000000000;
  LL ruiseki=0;
  for(int i=0;i<n-1;i++){
    ruiseki+=a[i];
    ans=min(ans,max(total-2*ruiseki,2*ruiseki-total));
  }
  cout << ans << endl;
  return 0;
}
