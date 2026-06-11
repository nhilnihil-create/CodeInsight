#include <bits/stdc++.h>
using namespace std;
long long gcd(long long x, long long y) {
    if (y == 0)return x;
    return gcd(y, x % y);
}
long long lcm(long long x, long long y) {
    return x / gcd(x, y) * y;
}
int main(){
  long long N; cin>>N;
  long long ans=0;
  for(int i=0;i<N;i++){
    long long a;cin>>a;
    if(i==0)ans=a;
    ans=lcm(ans,a);
  }
  cout<<ans<<endl;
}