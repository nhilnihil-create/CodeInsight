#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()

typedef long long ll;

const char nl = '\n' ;
const ll MOD = 1e9 + 7;
int main()
{
   ios_base::sync_with_stdio(0); cin.tie(0);
   int N, M; cin >> N >> M;
   int a[N], b[N], c[M], d[M];
   for(int i = 0; i < N; i++)
      cin >> a[i] >> b[i];
   for(int j = 0; j < M; j++)
      cin >> c[j] >> d[j];
   for(int i = 0; i < N; i++)
   {
      int ans, mindis = 1e9;
      for(int j = 0; j < M; j++)
      {
         int dis = abs(a[i] - c[j]) + abs(b[i] - d[j]);
         if(mindis > dis)
         {
            mindis = dis;
            ans = j;
         }
      }
      cout << ans+1 << nl;
   }


}
