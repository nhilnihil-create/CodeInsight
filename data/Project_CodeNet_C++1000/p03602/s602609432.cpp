# include <bits/stdc++.h>

# define pb push_back
# define fr first
# define sc second
# define mk make_pair
# define int long long

using namespace std;

const int inf = 1e9 + 7;
const int N = 305;

typedef long long ll;

int n, a[N][N], f[N][N], u[N][N], ans;

main()
{
      cin >> n;

      for(int i = 1; i <= n; i ++)
            for(int j = 1; j <= n; j ++)
                  cin >> a[i][j], f[i][j] = a[i][j], ans += a[i][j];

      for(int k = 1; k <= n; k ++)
            for(int i = 1; i <= n; i ++)
                  for(int j = 1; j <= n; j ++)
                  {
                        if(f[i][j] >= (f[i][k] + f[j][k]) && i != j && i != k && j != k)
                        {
                              f[i][j] = f[i][k] + f[j][k];
                              u[i][j] = 1;
                        }
                  }

      for(int i = 1; i <= n; i ++)
            for(int j = 1; j <= n; j ++)
            {
                  if(u[i][j]) ans -= a[i][j];
                  if(a[i][j] != f[i][j])
                  {
                        cout << -1 << endl;
                        return 0;
                  }
            }
      cout << ans / 2 << endl;
}