#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()

using namespace std;
using ll = long long;

const double PI = 3.14159265358979;

void solve()
{
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;

  vector<bool> w_seen(f / 100 + 1, false);
  vector<bool> s_seen(f + 1, false);

  queue<int> que;
  que.push(0);
  while(!que.empty())
  {
    int now = que.front();
    que.pop();

    if (now > f / 100) continue;
    if (w_seen[now]) continue;

    w_seen[now] = true;
    que.push(now + a);
    que.push(now + b);
  }

  que.push(0);
  while(!que.empty())
  {
    int now = que.front();
    que.pop();

    if (now > f) continue;
    if (s_seen[now]) continue;

    s_seen[now] = true;
    que.push(now + c);
    que.push(now + d);
  }

  vector<int> w;
  vector<int> s;
  for(int i = 0; i < (int)w_seen.size(); ++i) if(w_seen[i]) w.emplace_back(i);
  for(int i = 0; i < (int)s_seen.size(); ++i) if(s_seen[i]) s.emplace_back(i);

  int ans_sw = 100;
  int ans_s = 1;
  for(const auto& wv : w)
  for(const auto& sv : s)
  {
    if (wv * e < sv) break;

    int sw = wv * 100 + sv;
    if (sw > f) break;

    if (ans_s * sw <= sv * ans_sw)
    {
      ans_s = sv;
      ans_sw = sw;
    }
  }

  cout << ans_sw << " " << ans_s;
}

int main()
{
  fastio;
  solve();

  return 0;
}