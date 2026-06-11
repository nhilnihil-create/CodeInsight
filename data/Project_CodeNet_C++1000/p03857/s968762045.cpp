# include <bits/stdc++.h>

# define pb push_back
# define fr first
# define sc second
# define mk make_pair

using namespace std;

const int inf = 1e9 + 7;
const int N = 1e6 + 5;

typedef long long ll;

int n, k, l, p1[N], p2[N];
map < pair <int, int>, int> mp;

int get1(int v)
{
      if(p1[v] == v) return v;
      return p1[v] = get1(p1[v]);
}
int get2(int v)
{
      if(p2[v] == v) return v;
      return p2[v] = get2(p2[v]);
}

void unite1(int a, int b)
{
      a = get1(a);
      b = get1(b);
      p1[a] = b;
}

void unite2(int a, int b)
{
      a = get2(a);
      b = get2(b);
      p2[a] = b;
}

int main()
{
      cin >> n >> k >> l;

      for(int i = 1; i <= n; i ++)
            p1[i] = p2[i] = i;

      for(int i = 1; i <= k; i ++)
      {
            int a, b;
            cin >> a >> b;
            unite1(a, b);
      }

      for(int i = 1; i <= l; i ++)
      {
            int a, b;
            cin >> a >> b;
            unite2(a, b);
      }

      for(int i = 1; i <= n; i ++)
            mp[mk(get1(i), get2(i))] ++;

      for(int i = 1; i <= n; i ++)
            cout << mp[mk(get1(i), get2(i))] << " ";
}
