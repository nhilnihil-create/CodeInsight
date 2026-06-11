#include <iostream>
#include <algorithm>
#include <cmath>
#include <limits>
#include <vector>
#include <cstdio>
#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stdio.h>
#include <stack>
#include <queue>
#include <deque>
#include <numeric>
#include <bits/stdc++.h>
#include <utility>
#include <iomanip>

#define ALL(obj) (obj).begin(), (obj).end()
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define RFOR(i,a,b) for(int i = (a); (b) <= i; i--)
#define REP(i,n) for(int i = 0; i < (n); i++)
#define RREP(i,n) for(int i = n; n <= i; i--)
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define elif else if
#define MOD 1000000007
#define INF (1<<29)

using namespace std;

#define ld long double
#define ll long long

map <int ,int> mpa,mpb;
typedef pair<ll, ll> P;
priority_queue<P, vector<P>, greater<P>> pque;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  double N,A,B;
  cin >> N >> A >> B;
  vector<double> v;
  ll h;
  for(int i=0;i<N;i++){
    cin >> h;
    v.push_back(h);
  }
  ll ans=0;
  ll cnt=0;
  sort(v.begin(),v.end());
  ll lb=0,ub=1000000000;
  while(ub-lb>1){
    cnt=0;
    ll mid=(lb+ub)/2;
    for(int i=0;i<N;i++){
      if(v[i]<=B*mid)continue;
      else if(v[i]>B*mid){
        cnt+=ceil((v[i]-B*mid)/(A-B));
      }
    }
    if(cnt<=mid){
      ub=mid;
    }else{
      lb=mid;
    }
  }
  cout << lb+1 << endl;
  return 0;
}