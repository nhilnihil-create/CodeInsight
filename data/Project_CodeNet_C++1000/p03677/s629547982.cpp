#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <memory.h>
#include <queue>
#include <string.h>
using namespace std;

#define N 100002
int a[N],val[N];
long long ret[N];
int f(int x,int y,int m) {
  if(x<y) {
    return y-x;
  }
  return m + y-x;
}
vector<pair<int,int> > st[N];
void solve() {
  int n,m;scanf("%d %d ", &n,&m);
  for(int i=0;i<n;++i) {
    scanf("%d ", &a[i]);
  }
  priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >pq;
  long long curValue = 0;
  for(int i=0;i<n-1;++i) {
    int val = f(a[i],a[i+1],m);
    if(a[i]<a[i+1]) {
      curValue += val;
      st[a[i]].push_back(make_pair(a[i+1],val));
    } else {
      curValue += a[i+1];
      pq.push(make_pair(a[i+1],val));
      st[a[i]].push_back(make_pair(m+2,val));
    }
  }
  long long R = 1e18;
  for(int i=1;i<=m;++i) {
    while(!pq.empty()) {
      int lim = pq.top().first, val = pq.top().second;
      if(lim<i) {
        curValue += val;
        pq.pop();
      } else {
        break;
      }
    }
    R = min(R, curValue);
    while(!st[i].empty()) {
      pq.push(st[i].back());
      ++curValue;
      st[i].pop_back();
    }
    curValue -= pq.size();
  }
  printf("%lld\n", R);
}

int main() {
  //freopen("input.txt","r",stdin);
  solve();
  return 0;
}
