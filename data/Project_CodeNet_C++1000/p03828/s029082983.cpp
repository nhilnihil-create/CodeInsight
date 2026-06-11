#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi=vector<int>;
using vvi=vector<vi>;
using vl=vector<ll>;
using vvl=vector<vl>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;

#define rep(i, n) for(int i=0;i<(int)n;i++)
#define rep2(i, s, n) for(int i=(s);i<(int)n;i++)
int INF=1e9+7;

int main() {
  int N;
  cin >> N;
  vector<bool> is_prime(N+1,true);
  vi prime;
  for(int i=2;i*i<=N;i++) {
    if(!is_prime[i]) continue;
    for(int j=2;i*j<=N;j++) is_prime[i*j]=false;
  }
  rep2(i,2,N+1) {
    if(is_prime[i]) prime.push_back(i);
  }
  ll ans=1;
  for(int i:prime) {
    int num=N,count=0;
    while(num>0) {
      num/=i;
      count+=num;
    }
    ans=ans*(count+1)%INF;
  }
  cout << ans << endl;
}