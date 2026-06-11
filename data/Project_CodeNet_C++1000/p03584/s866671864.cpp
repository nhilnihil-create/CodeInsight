#include <bits/stdc++.h>
#define for0(i, n) for(int i = 0; i < n; i++)
#define for1(i, n) for(int i = 1; i <= n; i++)
#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define V vector<int>
#define VP vector<pair<int, int> >
#define FASTIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
#ifdef _WIN32
#include <windows.h>
#define print(x) PRINT(x, #x)
template<typename T> inline const void PRINT(T VARIABLE, string NAME)
{
#ifndef ONLINE_JUDGE /// ONLINE_JUDGE IS DEFINED ON CODEFORCES
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 10);
    cerr << NAME << " = " << VARIABLE;
    SetConsoleTextAttribute(hConsole, 7);
    cerr << '\n';
#endif
}
#else
#define print(x) 0
#endif
struct pair_hash
{
    template<typename T1, typename T2>
    size_t operator () (const pair<T1, T2> &p) const
    {
        auto h1 = hash<T1> {}(p.first);
        auto h2 = hash<T2> {}(p.second);
        return h1 ^ h2;
    }
};
typedef long long ll;
typedef unsigned long long ull;
const ll INFLL = 2 * (ll)1e18 + 100;
const int INFINT = 2 * (int)1e9 + 100;
//ifstream fin(".in");
//ofstream fout(".out");
void die()
{
    cout << "-1\n";
    exit(0);
}
const int NMAX = 1e5 + 5;
const int MOD = 1e9 + 7; /// careful here (7 or 9, 66.. etc)
const double PI = atan(1) * 4;
const double EPS = 1e-12;

int n, k;
struct mlc
{
    int a, b;
};

mlc v[NMAX];
ll sol;
ll solve(bitset<31> bit)
{
  ll ret = 0;
  for1(i, n)
  {
      bitset<31> a = bitset<31>(v[i].a);
      for0(ind, 31) if(a[ind] != bit[ind] && a[ind]) goto SKIP;
      ret += v[i].b;
      SKIP: ;
  }
  return ret;
}


int main()
{
    FASTIO;
    cin >> n >> k;
    for1(i, n)
        cin >> v[i].a >> v[i].b;
    bitset<31> K = bitset<31>(k);
    sol = solve(K);
    int pos = 30;
    for(; pos >= 0 && K[pos] == 0; pos--);

    while(pos >= 0)
    {
        if(K[pos] == 0)
        {
            pos--;
            continue;
        }
        bitset<31> cur;
        for(int i = 30; i > pos; i--) cur[i] = K[i];
        cur[pos] = 0;
        for(int i = pos - 1; i >= 0; i--) cur[i] = 1;
        sol = max(sol, solve(cur));
        pos--;
    }
    cout << sol;


    return 0;
}
