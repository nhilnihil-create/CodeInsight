
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cctype>
#include<math.h>
#include<string>
#include<string.h>
#include<stack>
#include<queue>
#include<vector>
#include<utility>
#include<set>
#include<map>
#include<stdlib.h>
#include<iomanip>

using namespace std;

#define ll long long
#define ld long double
#define EPS 0.0000000001
#define INF 1e9
#define MOD 1000000007
#define rep(i,n) for(i=0;i<(n);i++)
#define loop(i,a,n) for(i=a;i<(n);i++)
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)

typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;

int dp[5005][5005];

int main(void) {
  int i,j;
  int n,k;
  cin>>n>>k;
  vi a(n);
  rep(i,n)cin>>a[i];
  sort(all(a));

  int ok=-1;//不必要が確定している
  int ng=n;//必要が確定している
  
  while(ng-ok>1){
    int mid=(ok+ng)/2;
    bool c=true;

    //    cout<<mid<<endl;

    rep(i,n+1)rep(j,k+1)dp[i][j]=0;
    dp[0][0]=1;

    rep(i,n)rep(j,k){
      dp[i+1][j]|=dp[i][j];
      if(i!=mid)dp[i+1][min(j+a[i],k)]|=dp[i][j];
    }
    /*
    rep(i,n+1)rep(j,k+1)if(dp[i][j]>0)
      cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
    */
    rep(j,k)if(dp[n][j]>0){
      //       cout<<j<<endl;
      if(j+a[mid] >= k) c=false;
    }
    // cout<<mid<<" "<<c<<endl;

    if(c)ok=mid;
    else ng=mid;
  }

  cout<<ok+1<<endl;
}
/*
カードiを含むすべて集合の総和sum
sum >= k
sum-a[i] >= k
カードiは不必要

カードiを含まないある集合の総和sum
sum + a[i] >= k
sum < k
カードiは必要

a_1 < a_2 < … < a_n


a_iが不必要のときa_j (j<i)も不必要!!


a[i]を使わないとき和がk未満になるすべての集合のsum

dp[i][j]
a[i]までみたときに和がjとなるような集合の数

初期化
dp[0][0]=1
遷移
dp[i+1][j]=dp[i][j]
dp[i+1][min(j+a[i],k)]=dp[i][j]

O(NK * logN)


*/
