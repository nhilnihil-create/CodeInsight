#include <bits/stdc++.h>  // This will work only for g++ compiler.

#define for0(i, n) for (int i = 0; i < (int)(n); ++i) // 0 based indexing
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i) // 1 based indexing
#define forc(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i) // closed interver from l to r r inclusive
#define forr0(i, n) for (int i = (int)(n) - 1; i >= 0; --i) // reverse 0 based.
#define forr1(i, n) for (int i = (int)(n); i >= 1; --i) // reverse 1 based
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end() //Forward traversal
#define rall(x) (x).rbegin, (x).rend() //reverse traversal
#define tr(c,i) for(__typeof__((c)).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define sz(a) int((a).size())


using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;

void fast()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
void solve()
{
  ll a,b;
  cin >> a >> b;
  if(a<=b) cout << "0\n";
  else cout << a-b << "\n";
}
int main()
{
  fast();
  solve();

return 0;
}
