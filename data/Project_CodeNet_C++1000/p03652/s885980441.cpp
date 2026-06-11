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
  int N,M;
  cin>>N>>M;
  
  vector<vector<int>> A(N,vector<int>(M,0));
  rep(i,N) rep(j,M) cin>>A[i][j];

  int ans=N;
  vector<int> used(M+1,0);
  vector<int> pos(N+1,0);
  for(int i=0;i<M;i++){
    vector<int> num(M+1,0);
    for(int j=0;j<N;j++) num[A[j][pos[j]]]++;

    int ma=0,mat=0;
    for(int j=1;j<=M;j++){
      if(ma<num[j]){
        ma=num[j];
        mat=j;
      }
    }
    ans=min(ans,ma);
    used[mat]=1;

    for(int j=0;j<N;j++){
      while(pos[j]<M&&used[A[j][pos[j]]]==1) pos[j]++;
    }
  }

  cout<<ans<<endl;

  return 0;
}
