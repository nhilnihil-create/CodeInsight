#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ar array

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int maxn = 2e5 + 5;

int a[maxn], N, M;
ll sum1[maxn], sum2[maxn], sum3[maxn];

signed main(void)
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifdef LOCAL
    freopen("A.INP", "r", stdin);
    freopen("A.OUT", "w", stdout);
  #endif // LOCAL
  cin >> N >> M;
  for(int i = 1; i <= N; ++i)
    cin >> a[i];
  auto inc1 = [&](int l, int r, int val)
  {
    sum1[l] += val;
    sum1[r + 1] -= val;
  };
  auto inc2 = [&](int l, int r)
  {
    sum2[l]++; sum2[r + 1]--;
    sum3[l] += l - 1; sum3[r + 1] -= l - 1;
  };
  auto dbg = [&](void)
  {
    int d = 0;
    vector<int> p1(M + 5), p2(M + 5);
    for(int i = 1; i <= M; ++i){
      p1[i] = sum2[i];
      p2[i] = sum3[i];
      p1[i] += p1[i - 1];
      p2[i] += p2[i - 1];
    }
    for(int i = 1; i <= M; ++i){
      d += sum1[i];
      cerr << d - (i * p1[i] - p2[i]) << ' ' ;
      //cerr << d + sum[i] << ' ' << sum[i] << '\n';
    }
    cerr << '\n';
  };
  for(int i = 1; i < N; ++i){
    if(a[i] < a[i + 1]){
      int l = a[i], r = a[i + 1];
      inc1(1, l, r - l);
      inc1(r + 1, M, r - l);
      inc1(l + 1, r, 1 + r - l);
      inc2(l + 1, r);
    }
    else if(a[i + 1] < a[i]){
      int l = a[i + 1], r = a[i], dis = M - r + l;
      inc1(l + 1, r, dis);
      inc1(r + 1, M, 1 + l + M - r);
      inc2(r + 1, M);
      inc1(1, l, l + 1);
      inc2(1, l);
      //cerr << dis << '\n';
    }
    //dbg();
  }
  for(int i = 1; i <= M; ++i){
    sum1[i] += sum1[i - 1];
    sum2[i] += sum2[i - 1];
  }
  ll res = 1e18;
  for(int i = 1; i <= M; ++i){
    sum3[i] += sum3[i - 1];
    #ifdef LOCAL
      cerr << i << ' ' << -(sum2[i] * i - sum3[i]) + sum1[i] << '\n';
    #endif // LOCAL
    res = min(res, -(sum2[i] * i - sum3[i]) + sum1[i]);
  }
  cout << res;
}
