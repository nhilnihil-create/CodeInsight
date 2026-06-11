#include<iostream>
#include<algorithm>
#include<functional>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<tuple>
#include<stack>
#include<queue>
#include<deque>
#include<sstream>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<bitset>
#include<time.h>
#include<cstdlib>
#include<cassert>
#define ll long long
#define fi first
#define se second
using namespace std;

int n;
                   
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(10);
  cout<<fixed;
#ifdef LOCAL_DEFINE
    freopen("in", "r", stdin); 
    freopen("out","w",stdout);
#endif
  cin>>n;
  int maxi=0;
  for(int i=0;i<=n;i++){
    if(i*(i+1)>=2*n){
      maxi=i;
      break;
    }
  }
  for(int i=maxi;i>0;i--){
    if(n==0)break;
    if(n>=i){
      cout<<i<<"\n";
      n-=i;
    }
  }
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
  return 0;
}