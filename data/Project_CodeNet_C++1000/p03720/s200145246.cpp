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
   int N, M;
   cin >> N >> M;
   int ans[N+1] = {};
   for(int i = 0; i < M; i++)
   {
      int a, b; cin >> a >> b;
      ans[a]++;
      ans[b]++;
   }
   for(int i = 1; i <= N; i++)
      cout << ans[i] << nl;
   return 0;

}
