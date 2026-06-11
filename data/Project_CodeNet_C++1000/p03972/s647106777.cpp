#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
using namespace std;
typedef long long int ll;
typedef pair<ll, int> P;

int main()
{
	int w, h;
  scanf("%d %d", &w, &h);
  vector<P> v;
  for(int i=0; i<w; i++){
    ll p;
    scanf("%lld", &p);
	v.push_back(P(p, 0));
  }
  for(int i=0; i<h; i++){
    ll q;
    scanf("%lld", &q);
    v.push_back(P(q, 1));
  }
  ll c0=0, c1=0;
  sort(v.begin(), v.end());
  ll ans=0;
  for(auto p:v){
    int t=p.second;
    ll x=p.first;
    if(t==0){
      ans+=(x*((ll)h+1-c1));
      c0++;
    }else{
      ans+=(x*((ll)w+1-c0));
      c1++;
    }
  }
  printf("%lld\n", ans);
	return 0;
}