#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
  int N; scanf("%d", &N);
  vector<ll> h(N);
  for(int i = 0 ; i < N; i++){
    int a; scanf("%lld", &a); a--; h[a] = i;
  }
  
  set<ll> s;
  
  s.insert(-1); s.insert(N);
  ll ans = 0;
  for(int a = 0; a < N; a++){ 
    s.insert(h[a]);
    auto itr = s.lower_bound(h[a]);
    
    auto r1 = itr; auto r2 = itr;
    r1--; r2++;
    
    ans += (a+1)*(*r2-*itr)*(*itr-*r1);
  }
  
  printf("%lld\n",ans);
  
  return 0;
}
 