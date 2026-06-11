#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
const int N = 100001;
const int M = 100001;
int a[M];
//int x[N];
int m;
ll k;
vector<vector<ll>> x(2, vector<ll>(n));
void brute(){
  vector<ll> sx = x[0];
  int c = 1;
  for(int i = 0;i < k;i++){
    for(int j = 0;j < m;j++){
//      cout << a[j] << endl;
      sx[a[j]] = sx[a[j] - 1] + sx[a[j] + 1] - sx[a[j]];
    }
  }
  for(int i = 0;i < n;i++)
    cout << sx[i] << ' ';
  cout << endl;
  return ;
}
int main(){
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
//  srand(time(0));
//  cout << 10 << endl;
//  for(int i = 0;i < 10;i++){
//    cout << rand() % 1000 << ' ';
//  }
//  cout << endl;
//  cout << 10 << ' ' << 10;
//  cout << endl;
//  for(int i = 0;i < 10;i++)
//    cout << rand() % 8 + 2 << ' ';
//  return 0;
  scanf("%d", &n);
  x = vector<vector<ll>>(2, vector<ll>(n));
  for(int i = 0;i < n;i++)
    scanf("%lld", &x[0][i]);
  scanf("%d %lld", &m, &k);
  for(int i = 0;i < m;i++)
    scanf("%d", a + i), a[i]--;
  x[1] = x[0];
  for(int i = 0;i < m;i++){
    x[1][a[i]] = x[1][a[i] - 1] + x[1][a[i] + 1] - x[1][a[i]];
  }
  ll diff[2][n - 1];
  map<ll, vector<int>> mp;
  map<ll, int> mpc;
  vector<vector<int>> cs;
  for(int i = 0;i < n - 1;i++){
    diff[0][i] = x[0][i + 1] - x[0][i];
    diff[1][i] = x[1][i + 1] - x[1][i];
    mp[diff[0][i]].push_back(i);
    mpc[diff[0][i]] = 0;
//    cout << diff[0][i] << ' ';
  }
//  cout << endl;
//  for(int i = 0;i < n - 1;i++)
//    cout << diff[1][i] << ' ';
//  cout << endl;
//  brute();
  int p[n - 1];
  bool vis[n - 1];
  memset(vis, 0, sizeof(vis));
  for(int i = 0;i < n - 1;i++){
    int s = i;
    if(vis[s])continue;
    ll num = diff[1][s];
    int nx = mp[num][(mpc[num]++) % mp[num].size()];
    cs.push_back(vector<int>());
    vector<int>& c = cs[cs.size() - 1];
    c.push_back(s);
    while(nx != s){
      vis[nx] = 1;
      c.push_back(nx);
      ll num = diff[1][nx];
      nx = mp[num][(mpc[num]++) % mp[num].size()];
    }
//    for(auto el : c)
//      cout << el << ' ';
//    cout << endl;
  }
  ll diffr[n - 1];
  for(auto el : cs){
    int sh = k % el.size();
    for(int i = 0;i < el.size();i++){
      diffr[el[i]] = diff[0][el[(i + sh + el.size()) % el.size()]];
    }
  }
  ll res[n];
  res[0] = x[0][0];
  for(int i = 1;i < n;i++)
    res[i] = res[i - 1] + diffr[i - 1];
  for(int i = 0;i < n;i++)
    cout << res[i] << '\n';
//  for(int i = 0;i < n - 1;i++){
//    cout << diff[0][i] << ' ';
//  }
//  cout << endl;
//  for(int i = 0;i < n - 1;i++){
//    cout << diff[1][i] << ' ';
//  }
//  cout << endl;
  return 0;
}
