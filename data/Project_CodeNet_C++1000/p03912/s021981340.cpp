#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <functional>
using namespace std;

#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repl(i,0,n)
#define mp(a,b) make_pair((a),(b))
#define pb(a) push_back((a))
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<((x))<<endl
#define fi first
#define se second

#define INF 2147483600
#define MX 100000

int main(){
  int n,m;
  cin>>n>>m;
  vector<int> cnt_mod(m, 0);
  vector<int> cnt(MX+1,0);
  rep(i,n){
    int d;
    scanf("%d", &d);
    cnt_mod[d%m]++;
    cnt[d]++;
  }

  int res=cnt_mod[0]/2; //mでわってあまり0
  if(m%2==0) res += cnt_mod[m/2]/2; //偶数なら

  repl(i,1,(m+1)/2){
    // mod i, mod m-i のくみ
    int mn = min(cnt_mod[i], cnt_mod[m-i]);
    res += mn;
    // mod iのほう
    if(cnt_mod[i]>mn){
      int same=0, no=0;
      for(int k=i; k<=MX; k+=m){
        same += cnt[k]/2;
        no += cnt[k]%2;
      } //cout<<mn<<" "<<no<<" "<<same<<endl;
      if(mn>=no && same>0) res += (2*same-(mn-no))/2;
      else if(same>0) res += same;
    }

    // mod m-iのほう
    else if(cnt_mod[m-i]>mn){
      int same=0, no=0;
      for(int k=m-i; k<=MX; k+=m){
        same += cnt[k]/2;
        no += cnt[k]%2;
      } //cout<<mn<<" "<<no<<" "<<same<<endl;
      if(mn>=no && same>0) res += (2*same-(mn-no))/2;
      else if(same>0) res += same;
    }
  }

  cout << res<<endl;

  return 0;
}
