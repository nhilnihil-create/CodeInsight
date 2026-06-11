# include <bits/stdc++.h>

# define pb push_back
# define fr first
# define sc second
# define mk make_pair

using namespace std;

const int inf = 1e9 + 7;
const int N = 1e6 + 5;

typedef long long ll;

int n, m, x[N], ans, c[N];
vector <int> v[N], a, b;

int main()
{
      cin >> n >> m;

      for(int i = 1; i <= n; i ++)
      {
            cin >> x[i];
            v[x[i] % m].pb(x[i]);
      }

      ans += v[0].size() / 2;
      if(m % 2 == 0)
            ans += v[m / 2].size() / 2;

      for(int i = 1; i <= m / 2; i ++)
      {
            if(i == (m - i)) continue;
            a = v[i];
            b = v[m - i];
            if(a.size() > b.size())
                  a.swap(b);
            int need = (b.size() - a.size()) / 2, cnt = 0;
            sort(b.begin(), b.end());
            for(int j : b)
                  c[j] ++;
            for(int j = 0; j < b.size(); j ++)
                  if(j == 0 || b[j - 1] != b[j])
                        cnt += c[b[j]] / 2;
            for(int j : b)
                  c[j] --;
            ans += a.size() + min(need, cnt);
      }

      cout << ans << endl;
}
