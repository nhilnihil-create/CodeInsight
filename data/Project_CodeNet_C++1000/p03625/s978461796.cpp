#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
#define rrep(i, n) for(int i = n-1; i >= 0; --i)
using namespace std;

int main(){
  long long s = 0; int n; scanf("%d", &n);
  map<int, int> m;
  rep(i, n){
    int a; scanf("%d", &a);
    m[a]++;
  }
  priority_queue<int> p;
  for(auto q: m){
    if(q.second > 3) p.push(q.first);
    if(q.second > 1) p.push(q.first);
  }
  if(p.size() > 1){
    s = p.top(); p.pop(); s *= p.top();
  }
  printf("%ld\n", s);
  return 0;
}