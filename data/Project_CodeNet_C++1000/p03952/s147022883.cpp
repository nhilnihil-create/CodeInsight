#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#include <set>
#include <tuple>
#define mkp make_pair
#define mkt make_tuple
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;

int main(){
  int N,X;
  cin>>N>>X;

  if(X==1||X==2*N-1){
    cout<<"No"<<endl;
    return 0;
  }

  vector<int> ans(2*N,0);
  vector<int> used(2*N,0);
  used[X-1]=1;used[X]=1;used[X+1]=1;
  ans[N]=X;
  ans[N-1]=X+1;
  ans[N+1]=X-1;

  int now=1;
  for(int i=1;i<=2*N-1;i++){
    if(ans[i]==0){
      while(now<=2*N-1&&used[now]==1) now++;
      ans[i]=now;
      used[now]=1;
    }
  }
  cout<<"Yes"<<endl;
  for(int i=1;i<=2*N-1;i++) cout<<ans[i]<<endl;

  return 0;
}
