#include <bits/stdc++.h>

#define INF 1 << 29
#define REP(i,n) for(int i=0; i<(int)(n); i++)
#define FOR(i,k,n) for(int i=(k);i<(int)(n);i++)

using namespace std;

typedef pair<int,int> pii;
typedef long long int ll;

void gen_sosuu(int sosuu[]){
  REP(i,100010){
    sosuu[i] = true;
  }
  sosuu[0] = false;
  sosuu[1] = false;
  sosuu[2] = true;
  FOR(i,2,sqrt(100000)+1){
    if(sosuu[i] == false) continue;
    for(int j = 2; i*j<=100000;j++){
      //printf("%d %d %d\n",i*j,i,j);
      sosuu[i*j] =false;
    }
  }
}

bool dp[5010][5010] = {{false}};
int n,k;

vector<ll> a;

bool is_ok(int m){
  REP(i,n){
    REP(j,k) dp[i+1][j] = false;
    REP(j,k){
      if(dp[i][j]){
        dp[i+1][j] = true;
        if(i!=m && j+a[i]<k) dp[i+1][j+a[i]] = true;
      }
    }
  }
  FOR(i,max(0ll,k-a[m]),k) if(dp[n][i]) return true;
  return false;
}


int main(){
  scanf("%d %d",&n,&k);
  REP(i,n){
    ll x;
    scanf("%lld",&x);
    a.push_back(x);
  }
  sort(a.begin(),a.end());
  dp[0][0] = true;
  int l = 0, r = n+1, m;
  while(r-l>1){
    m = (r+l)/2;
    (is_ok(m-1) ? r : l) = m;
  }
  printf("%d\n",l);
}

/*
ll n,k;
vector<ll> a;

ll sum = 0;

int main(){
  scanf("%lld %lld",&n,&k);
  REP(i,n){
    int x;
    scanf("%lld",&x);
    a.push_back(x);
  }
  sort(a.begin(),a.end());
  int from = 0;
  REP(to,a.size()){
    sum += a[to];
    while(sum-a[from]>=k){
      sum -= a[from];
      from++;
    }
    //printf("%d %d %d %d\n",sum,sum-a[from],a[from],a[to]);
    if(sum>=k) break;
  }
  if(sum<k){
    printf("%d\n",n);
    return 0;
  }
  printf("%d\n",from);
  return 0;
}
*/
