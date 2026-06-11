//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using ld = long double;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
template<class T> using PQ = priority_queue<T>;
template<class T> using PQG = priority_queue<T, vector<T>, greater<T> >;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;
template<typename T1, typename T2>
inline bool chmax(T1 &a, T2 b) {return a < b && (a = b, true);}
template<typename T1, typename T2>
inline bool chmin(T1 &a, T2 b) {return a > b && (a = b, true);}
template<typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p) { return is >> p.first >> p.second;}
template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) { return os << p.first << ' ' << p.second;}

template<class T>
struct SegTree {
  using FX = function<T(T, T)>;
  int n;
  FX fx;
  const T ex;
  vector<T> dat;
  SegTree(int n_, FX fx_, T ex_):fx(fx_), ex(ex_), n(1) {
    while(n < n_) n <<= 1;
    dat.assign((n<<1)-1, ex);
  }
  inline int chld(int k) {return (k<<1)+1;}
  inline int chrd(int k) {return (k<<1)+2;}
  void update(int i, T x) {
    i += n-1;
    dat[i] = x;
    while(i) {
      i = (i-1)>>1;
      dat[i] = fx(dat[chld(i)], dat[chrd(i)]);
    }
  }
  inline T query(int a, int b) {return query(a, b, 0, 0, n);}
  T query(int a, int b, int k, int l, int r) {
    if(r <= a || b <= l) return ex;
    if(a <= l && r <= b) return dat[k];
    T vl = query(a, b, chld(k), l, (l+r)>>1);
    T vr = query(a, b, chrd(k), (l+r)>>1, r);
    return fx(vl, vr);
  }
  T operator[](const int i) const {return dat[i+n-1];}
};

const size_t N = 2e5+10;

//head

string s, ans;
int n;
vi al[26];
int pl[26];
int ppl;
bitset<N> bits;
PQ<int> q;
vi G[N];
int last;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> s;
  n = s.size();
  rep(i, 26) al[i].emplace_back(-1);
  rep(i, n) {
    al[s[i]-'a'].emplace_back(i);
  }

  SegTree<int> seg(n+1, [](int i, int j)->int{return min(i, j);}, INF);
  seg.update(0, 0);

  rep(i, n) {
    auto itr = lower_bound(all(al[s[i]-'a']), i);
    seg.update(i+1, seg.query(*(itr-1)+1, i+1)+1);
  }

  rep(i, 26) {
    if(al[i].size() == 1) {
      cout << char(i + 'a') << endl;
      return 0;
    }
    pl[i] = al[i][al[i].size()-1];
  }
  int jf = *min_element(pl, pl+26);
  ppl = seg.query(jf+1, n+1);

  for(int i = jf+1; i <= n; i++) {
    if(seg[i] == ppl) {
      q.emplace(i-1);
      bits.set(i);
    }
  }

  while(q.top() != -1) {
    int now = q.top();
    q.pop();
    auto itr = lower_bound(all(al[s[now]-'a']), now);
    for(int i = *(itr-1)+1; i < now+1; i++) {
      if(seg[i] == seg[now+1]-1) {
        if(!bits.test(i)) {
          bits.set(i);
          q.emplace(i-1);
        }
        G[i].emplace_back(now+1);
      }
    }
  }

  last = 0;
  while(!G[last].empty()) {
    char c = 'z'+1;
    int nex;
    for(int ne:G[last]) {
      if(chmin(c, s[ne-1])) nex = ne;
    }
    last = nex;
    ans += c;
  }

  rep(i, 26) {
    if(al[i][al[i].size()-1] < last) {
      cout << ans << char(i+'a') << endl;
      return 0;
    }
  }
}