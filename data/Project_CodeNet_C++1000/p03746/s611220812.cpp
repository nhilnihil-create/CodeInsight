#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = pow(10, 9) + 7;
//const int MOD = 998244353;
//const int MOD = ;
int mod(int A, int M) {return (A % M + M) % M;}
const int INF = 1LL << 60;
template <class T> bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return false;}
template <class T> bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return false;}
int divCeil(int A, int B) {return (A + (B - 1)) / B;}
int myctoi(char C) {return C - 48;}
char myitoc(int N) {return '0' + N;}

vector<vector<int>> G(111111);
vector<bool> visited(111111, false);
vector<int> ans0, ans1;
bool fin = false;
bool dfs(int V, int T)
{
  if (fin) return false;
  if (visited.at(V)) return false;
  visited.at(V) = true;

  if (T == 0) ans0.push_back(V);
  else ans1.push_back(V);

  bool fin0 = true;
  for (int i = 0; i < G.at(V).size(); i++)
  {
    if (dfs(G.at(V).at(i), T)) fin0 = false;
  }
  if (fin0) fin = true;

  return true;
}

signed main()
{
  int N, M;
  cin >> N >> M;
  for (int i = 0; i < M; i++)
  {
    int a, b;
    cin >> a >> b;
    G.at(a).push_back(b);
    G.at(b).push_back(a);
  }
  
  dfs(1, 0);
  visited.at(1) = false;
  fin = false;
  dfs(1, 1);

  int L0 = ans0.size(), L1 = ans1.size();
  cout << L0 + L1 - 1 << endl;
  cerr << L0 << " " << L1 << endl;
  for (int i = L1 - 1; i > 0; i--)
  {
    cout << ans1.at(i) << " ";
  }
  for (int i = 0; i < L0; i++)
  {
    cout << ans0.at(i);
    if (i == L0 - 1) cout << endl;
    else cout << " ";
  }
}