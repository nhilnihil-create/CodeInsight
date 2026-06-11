#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> p_ll;

template<class T>
void debug(T itr1, T itr2) { auto now = itr1; while(now<itr2) { cout << *now << " "; now++; } cout << endl; }
#define repr(i,from,to) for (int i=(int)from; i<(int)to; i++)
#define all(vec) vec.begin(), vec.end()
#define rep(i,N) repr(i,0,N)
#define per(i,N) for (int i=(int)N-1; i>=0; i--)

const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;

struct res { ll num; ll top; ll size; };

int main() {
  int N; cin >> N;
  map<int, priority_queue<int, vector<int>, greater<int>>, greater<int>> a; a[0].push(0);
  rep(i,N) { int tmp; cin >> tmp; a[tmp].push(i); }

  vector<res> count;
  for (auto x: a) count.push_back({x.first,x.second.top(),(ll)x.second.size()});

  ll result[N] = {};
  ll now = 0;
  repr(i,1,count.size()) {
    now += count[i-1].size;
    count[i].top = min(count[i].top, count[i-1].top);
    result[count[i-1].top] += (count[i-1].num-count[i].num) * now;
  }
  rep(i,N) cout << result[i] << endl;
  return 0;
}