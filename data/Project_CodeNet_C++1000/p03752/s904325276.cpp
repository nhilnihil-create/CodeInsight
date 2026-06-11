#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const ll INF = -1e18;
const int I=2001;
int input() {int x; cin>>x; return x;}

int main(){
  int n,k; cin>>n>>k;
  ll a[n]; for(int i=0;i<n;i++) cin>>a[i];
  ll an=3.1415926535e14;
  for(int i=0;i<(1<<n);i++) {
    ll sm=0, hi=0, kk=0; bool p[n];
    for(int j=0;j<n;j++) {
      if (i & (1<<j)) p[j]=true, kk++;
      else p[j]=false;
    }
    if (kk < k) continue;
    for(int j=0;j<n;j++) {
      ll sz=a[j];
      if (p[j]) {
        sm += max(0LL, hi-sz+1);
        //cerr<<j<<" "<<hi<<" "<<sz<<" "<<hi-sz+1<<endl;
        sz = max(a[j], hi+1);
      }
      //cout<<hi<<" "<<sz<<" ";
      hi=max(hi,sz);
      //cout<<hi<<" "<<sz<<endl;
    }
    //cout<<i<<" "<<sm<<endl;
    an = min(an,sm);
  }
  cout<<an<<endl;
}