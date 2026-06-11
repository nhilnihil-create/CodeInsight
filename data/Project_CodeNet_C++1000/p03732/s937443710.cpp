#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
#define MODSIZE 1000000007

int main(){
  ll n,W;
  int i,j,k,l;
  ll w,w1;
  ll value;
  ll max = -100100100100;
  pair <ll,ll> a[106];
  vector <ll> v[5];

  scanf("%lld %lld", &n, &W);
  for(i = 0;i < n;i++){
    scanf("%lld %lld", &a[i].first, &a[i].second);
  }

  w1 = a[0].first;

  sort(a,a + n);

  // for(i = 0;i < n;i++) printf("%lld %lld\n", a[i].first, a[i].second);
  j = 0;
  for(i = 0;i < n - 1;i++){
    v[j].push_back(a[i].second);
    if(a[i].first != a[i + 1].first) j++;
  }

  v[j].push_back(a[n - 1].second);

  for(i = 0;i < 4;i++){
    sort(v[i].begin(),v[i].end());
    reverse(v[i].begin(),v[i].end());
  }
  
  for(i = 0;i <= v[0].size();i++){
    for(j = 0;j <= v[1].size();j++){
      for(k = 0;k <= v[2].size();k++){
        for(l = 0;l <= v[3].size();l++){
          value = 0;
          w = i*w1 + j*(w1 + 1) + k*(w1 + 2) + l*(w1 + 3);

          if(w > W) break;

          int d;
          for(d = 0;d < i;d++) value += v[0][d];
          for(d = 0;d < j;d++) value += v[1][d];
          for(d = 0;d < k;d++) value += v[2][d];
          for(d = 0;d < l;d++) value += v[3][d];

          if(value > max) max = value;
        }
      }
    }
  }

  printf("%lld\n", max);

  return 0;
}