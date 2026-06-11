/// awoooooo

# include <bits/stdc++.h>
# define sz(x) (int)((x).size())

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair < int, int > pii;

const int N = (int)2e5 + 5;
const int inf = (int)1e9 + 7;

int n, m;
int a[301][301], cur[301], u[301], cnt[301];
set < pii > s;

int ok(int val){
  s.clear();
  for(int i = 1; i <= m; ++i){
    cnt[i] = 0;
  }
  for(int i = 1; i <= n; ++i){
    cnt[a[i][1]]++;
    cur[i] = 1;
  }
  for(int i = 1; i <= m; ++i){
    u[i] = 0;
    s.insert(make_pair(cnt[i], i));
  }
  while(true){
    if(s.rbegin() -> first <= val){
      break;
    }
    int p = s.rbegin() -> second;
    s.erase(--s.end());
    u[p] = 1;
    for(int i = 1; i <= n; ++i){
      int changed = 0;
      while(cur[i] <= m && u[a[i][cur[i]]]) ++cur[i], changed = 1;
      if(cur[i] > m){
        return 0;
      }
      if(changed){
        s.erase(make_pair(cnt[a[i][cur[i]]], a[i][cur[i]]));
        cnt[a[i][cur[i]]]++;
        s.insert(make_pair(cnt[a[i][cur[i]]], a[i][cur[i]]));
      }
    }
  }
  return 1;
}

int main(){
  scanf("%d %d", &n, &m);
  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      scanf("%d", a[i] + j);
    }
  }
  int ans = n;
  for(int i = 10; i >= 0; --i){
    if(ans - (1 << i) >= 0 && ok(ans - (1 << i))){
      ans -= (1 << i);
    }
  }
  printf("%d", ans);
  return 0;
}
