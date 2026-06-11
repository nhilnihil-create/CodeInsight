#include <bits/stdc++.h>
using namespace std;
#define null NULL
#define mp make_pair
#define pb(a) push_back(a)
#define sz(a) ((int)(a).size())
#define all(a) a.begin() , a.end()
#define fi first
#define se second
#define relaxMin(a , b) (a) = min((a),(b))
#define relaxMax(a , b) (a) = max((a),(b))
#define SQR(a) ((a)*(a))
#define PI 3.14159265358979323846
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long ll;

typedef deque<int> dq;

ll n, up = 1;

pair<dq, dq> Build(ll n){
  pair<dq, dq> res;

  if(n == 1){
    res.fi.pb(up);
    res.se.pb(up++);
    return res;
  }

  if(n == 2){
    res.fi.pb(up), res.fi.pb(up + 1);
    res.se.pb(up + 1), res.se.pb(up);
    up += 2;
    return res;
  }

  if((n & 1) == 0){
    res = Build(n - 1);
    res.fi.pb(up);
    res.se.push_front(up++);
    return res;
  }

  ll m = (n - 1) / 2;
  res = Build(m);
  res.fi.push_front(up);
  res.se.push_front(up++);
  return res;
}

int main(){
  cin >> n;
  auto _res = Build(n);

  vi res;
  for(int e : _res.fi) res.pb(e);
  for(int e : _res.se) res.pb(e);

  printf("%d\n", sz(res));
  for(int i = 0;i < sz(res);++i)
    printf("%d%c", res[i], i + 1 == sz(res) ? '\n' : ' ');

  return 0;
}
