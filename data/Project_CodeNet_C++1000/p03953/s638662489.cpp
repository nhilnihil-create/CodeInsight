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
vector<ll> x;
//void brute(){
//  vector<ll> sx = x[0];
//  int c = 1;
//  for(int i = 0;i < k;i++){
//    for(int j = 0;j < m;j++){
////      cout << a[j] << endl;
//      sx[a[j]] = sx[a[j] - 1] + sx[a[j] + 1] - sx[a[j]];
//    }
//  }
//  for(int i = 0;i < n;i++)
//    cout << sx[i] << ' ';
//  cout << endl;
//  return ;
//}
vector<int> perm(const vector<int>& v, const vector<int>& p){
  vector<int> res(v.size());
  for(int i = 0;i < p.size();i++)
    res[i] = v[p[i]];
  return res;
}
vector<int> compose(const vector<int>& a, const vector<int>& b){
  vector<int> x(a.size());
  for(int i = 0;i < a.size();i++)
    x[i] = i;
  x = perm(x, b);
  x = perm(x, a);
  return x;
}
vector<int> power(const vector<int>& p, ll k){
  if(k == 1)return p;
  return k % 2 == 0 ? power(compose(p, p), k / 2) : compose(p, power(p, k - 1));
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
  x = vector<ll>(n);
  for(int i = 0;i < n;i++)
    scanf("%lld", &x[i]);
  scanf("%d %lld", &m, &k);
  for(int i = 0;i < m;i++)
    scanf("%d", a + i), a[i]--;
  vector<int> diff(n - 1);
  for(int i = 0;i < n - 1;i++)
    diff[i] = x[i + 1] - x[i];
  vector<int> p(n - 1);
  for(int i = 0;i < n - 1;i++)
    p[i] = i;
  for(int i = 0;i < m;i++)
    swap(p[a[i]], p[a[i] - 1]);
  p = power(p, k);
  vector<int> dd = perm(diff, p);
  ll res[n];
  res[0] = x[0];
  for(int i = 0;i < n - 1;i++)
    res[i + 1] = res[i] + dd[i];
  for(int i = 0;i < n;i++)
    cout << res[i] << endl;
  return 0;
}
