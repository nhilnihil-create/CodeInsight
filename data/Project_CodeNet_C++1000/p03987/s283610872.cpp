/// awoooooo

# include <bits/stdc++.h>
# define sz(x) (int)((x).size())

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair < int, int > pii;

const int N = (int)2e5 + 5;
const int inf = (int)1e9 + 7;

int n;
int a[N];
int l[N], r[N];
stack < int > s;

int main(){
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    scanf("%d", a + i);
  }
  for(int i = 1; i <= n; ++i){
    while(!s.empty() && a[s.top()] > a[i]){
      r[s.top()] = i;
      s.pop();
    }
    s.push(i);
  }
  while(!s.empty()){
    r[s.top()] = n + 1;
    s.pop();
  }
  for(int i = n; i >= 1; --i){
    while(!s.empty() && a[s.top()] > a[i]){
      l[s.top()] = i;
      s.pop();
    }
    s.push(i);
  }
  while(!s.empty()){
    l[s.top()] = 0;
    s.pop();
  }
  ll ans = 0;
  for(int i = 1; i <= n; ++i){
    ans += (i - l[i]) * 1ll * (r[i] - i) * a[i];
  }
  printf("%lld", ans);

  return 0;
}
