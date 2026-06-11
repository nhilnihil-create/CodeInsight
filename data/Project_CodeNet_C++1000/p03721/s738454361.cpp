#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
#define MODSIZE 1000000007
priority_queue<int, vector<int>, greater<int> > PQ; // 昇順PQ
// priority_queue<int> PQ;

int main(){
  vector <pair <ll,ll>> q;
  ll n,k;

  scanf("%lld %lld", &n, &k);

  int i;
  for(i = 0;i < n;i++){
    ll a,b;
    scanf("%lld %lld", &a, &b);
    q.push_back(make_pair(a,b));
  }

  sort(q.begin(),q.end());

  i = 0;
  while(1){
    if(q[i].second >= k){
      printf("%lld\n", q[i].first);
      break;
    }

    k -= q[i].second;
    i++;
  }

  return 0;
}
