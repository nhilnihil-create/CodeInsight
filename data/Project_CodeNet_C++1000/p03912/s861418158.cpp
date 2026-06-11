#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);i++)
using namespace std;
typedef pair<int,int> P;
int N, M;
int X[100010];
int v[100010];
vector<P> mod[100010];
int modsum[100010];
int main(){
  cin >> N >> M;
  
  REP(i,N){
    cin >> X[i];
    v[ X[i] ]++;
  }
  REP(i, 100010){
    if( v[i] > 0 ){
      mod[ i % M ].emplace_back( v[i], i );
      modsum[ i % M ] += v[i];
    }
  }
  int ans = 0;
  ans += modsum[0] / 2;
  if( M % 2 == 0 ){
    ans += modsum[ M / 2 ] / 2;
  }
  for(int i = 1; i < M - i; i++ ){
    int j = M - i;
    int mutch = min( modsum[i] , modsum[j] );
    //cout << "mutch=" << mutch << endl;
    ans += mutch;
    int d = abs( modsum[i] - modsum[j] );
    if( d == 0 ) continue;
    if( modsum[j] < modsum[i] ){
      // modsum[j] の方が大きくなるようにする
      j = i;
    }
    // 奇数のものの個数を調べる
    int od = 0;
    REP( k, mod[j].size() ){
      if( mod[j][k].first % 2 == 1 ) od++;
    }
    if( mutch >= od ){
      ans += (modsum[j] - mutch) / 2;
    }else{
      ans += (modsum[j] - od) / 2;
    }
  }
  cout << ans << endl;
}
