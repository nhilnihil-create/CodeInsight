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
using namespace std;

#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repl(i,0,n)
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define fi first
#define se second

#define INF 2147483600

typedef pair<int, int> P;

int main(){
  int w,h;
  cin>>w>>h;
  vector<int> p(w), q(h);
  rep(i,w) scanf("%d", &p[i]);
  rep(i,h) scanf("%d", &q[i]);

  vector<P> vec(w+h);
  rep(i,w) vec[i] = mp(p[i], 0);
  rep(i,h) vec[i+w] = mp(q[i], 1);

  sort(all(vec));
  int nw=w+1, nh=h+1;
  long res=0;
  rep(i, w+h){
    if(vec[i].se==0){ //p w のほうをつかう
      res += (long)vec[i].fi * nh;
      nw--;
    } else {
      res += (long)vec[i].fi * nw;
      nh--;
    }
  }
  cout<<res<<endl;

  return 0;
}
