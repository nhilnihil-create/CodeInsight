#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

int main(){
  int n,t;
  cin >> n >> t;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  int mi=a[0],mav=0;
  for(int i=1;i<n;i++){
    mav=max(mav,a[i]-mi);
    mi=min(mi,a[i]);
  }
  mi=a[0];
  int mic=1,mac=0;
  int ans=0;
  for(int i=1;i<n;i++){
    if(a[i]-mi==mav) mac++;
    if(a[i]==mi) mic++;
    else if(a[i]<mi){
      ans+=min(mic,mac);
      mic=1,mac=0;
      mi=a[i];
    }
  }
  ans+=min(mic,mac);
  cout << ans << endl;
  return 0;
}
