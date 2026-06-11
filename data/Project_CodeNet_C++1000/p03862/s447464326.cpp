#include <iostream>
#include <vector>
#define rep(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;
typedef long long LL;

int main(){
  int N;
  LL x;
  cin >> N >> x;
  vector<LL> a(N);
  rep(i,N) cin >> a[i];
  LL ans=0;
  rep(i,N-1){
    if(a[i]+a[i+1]>x){
      ans+=a[i]+a[i+1]-x;
      if(x>=a[i]) a[i+1]=x-a[i];
      else a[i+1]=0;
    }
  }
  cout << ans << endl;

  return 0;
}
