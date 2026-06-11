/*
　 　 　 　 　 　　/T￣「ヽ
　 　 　 　 　 　 │ ｌ　|　|
　 　　　　　　　　|　l　l　!
　 　 　 　 　 　 　l　l　! L_
　 　 　　　　　／ヽ　　　　｀丶 　　　　, -─┐
　　　　　　　/　ｎ　　ｎ 　　,r‐ヽ 　 ／　,r─,'
　 　　　ャ‐ﾊ 　ﾋ! 　 ﾋ! 　/ 　 └ｧ′／ 　/
　 　　　ム ヽ! ＿'__'_　　j 　　　く ／ 　　/
　 　 　 　 ヽﾍ! 　 　　￣（-‐ヽrｰﾄ──/
　 　　　　　　　｀Tヽ､　弋 　 Y　　ト--'
　 　　　　　　　　ｊ_,_,ﾉ￣｀j_,_,ﾉ｀'‐'′No.258:ミズゴロウ
*/
//AOJだとboostライブラリは使えない...(悲しい)
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;
#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
//using INT = mp::cpp_int;
using namespace std;
using ll = long long;
using vec = vector<ll>;
using vect = vector<double>;
using Graph = vector<vector<ll>>;
#define loop(i, n) for (ll i = 0; i < n; i++)
#define Loop(i, m, n) for (ll i = m; i < n; i++)
#define pool(i, n) for (ll i = n; i >= 0; i--)
#define Pool(i, m, n) for (ll i = n; i >= m; i--)
#define mod 1000000007ll;
#define setbit bitset<8>
#define flagcount __builtin_popcount
#define flag(x) (1 << x)
#define flagadd(bit, x) bit |= flag(x)
#define flagpop(bit, x) bit &= ~flag(x)
#define flagon(bit, i) bit &flag(i)
#define flagoff(bit, i) !(bit & (1 << i))
#define all(v) v.begin(), v.end()
#define low2way(v, x) lower_bound(all(v), x)
#define high2way(v, x) upper_bound(all(v), x)
#define count2way(v, x) high2way(v, x) - low2way(v, x)
#define lower(v, x) low2way(v, x) - v.begin()       //1番左が0、もし見つから無いならｎを出力
#define higher(v, x) high2way(v, x) - v.begin() - 1 //1番左が0、もし見つからないならn-1を出力（注意）
#define putout(a) cout << a << endl
#define putout2(a, b) \
  putout(a);          \
  putout(b)
#define putout3(a, b, c) \
  putout(a);             \
  putout(b);             \
  putout(c)
#define putout4(a, b, c, d) \
  putout(a);                \
  putout(b);                \
  putout(c);                \
  putout(d)
#define putout5(a, b, c, d, e) \
  putout(a);                   \
  putout(b);                   \
  putout(c);                   \
  putout(d);                   \
  putout(e)
#define Gput(a, b) G[a].push_back(b)
#define cin1(a) cin >> a
#define cin2(a, b) cin >> a >> b
#define cin3(a, b, c) cin >> a >> b >> c
#define cin4(a, b, c, d) cin >> a >> b >> c >> d
#define cin5(a, b, c, d, e) cin >> a >> b >> c >> d >> e
#define sum(v) accumulate(all(v), 0ll)
#define gcd(x, y) __gcd(x, y)
ll ctoi(char c)
{
  if (c >= '0' && c <= '9')
  {
    return c - '0';
  }
  return 0;
}
template <typename T>
T lcm(T x, T y)
{
  T z = gcd(x, y);
  return x * y / z;
}

template <typename T>
T primejudge(T n)
{
  if (n < 2)
    return 0;
  else if (n == 2)
    return 1;
  else if (n % 2 == 0)
    return 0;
  T sqrtn = sqrt(n);
  Loop(i, 3, sqrtn + 1)
  {
    if (n % i == 0)
    {
      return 0;
    }
    i++;
  }
  return 1;
}
template <typename T>
T modinv(T a, T m)
{
  T b = m, u = 1, v = 0;
  while (b)
  {
    T t = a / b;
    a -= t * b;
    swap(a, b);
    u -= t * v;
    swap(u, v);
  }
  u %= m;
  if (u < 0)
    u += m;
  return u;
}
//場合によって使い分ける
//const ll dx[4]={1,0,-1,0};
//const ll dy[4]={0,1,0,-1};
const ll dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

/*
//TIMESTAMPbfs
vector<bool> seen;
vec first;
vec last;
void dfs(const Graph &G,ll v,ll &time){
  if(!(seen[v])){
  seen[v]=true;
  first[v]=time++;
  for(auto next_v:G[v]){
    if(seen[next_v])continue;
    dfs(G,next_v,time);
  }
  last[v]=time++;
  }
}
//main関数内で
  seen.assign(n, false); // 全頂点を「未訪問」に初期化
  first.resize(n);
  last.resize(n);
*/
//多次元配列の宣言名
//vector<vector<ll>> field(h, vector<ll>(w));
//記念
/*
field.assign(h, vector<ll>(w, 0));
vector<vector<ll>> field;
void dfs(ll x,ll y,ll h,ll w){
  field[x][y]=0;
  loop(i,8){
    ll next_x=x+dx[i],next_y=y+dy[i];
    if(next_x<0||next_x>=h||next_y<0||next_y>=w)continue;
    if(field[next_x][next_y]==0)continue;
    dfs(next_x,next_y,h,w);
  }
}
*/
template <class T>
inline void chmax(T &a, T b)
{
  if (a < b)
    a = b;
}
template <class T>
inline void chmin(T &a, T b)
{
  if (a > b)
    a = b;
}
//頂点fromから頂点toへと結ぶコストcostの有向辺
struct edge
{
  ll from;
  ll cost;
  ll to;
};
ll V, E;
vector<edge> side;
vec dist;
vector<bool> find_negative_loop;
/*
始点vから各頂点への最短距離を求め(経路が存在しなければ1e18)、
また各頂点につくまでに負閉路が存在するかどうかも調べる
*/
void bellman_ford(ll v)
{
  loop(i, V) dist[i] = 1e18;
  dist[v] = 0;
  ll count = 0;
  while ("neko")
  {
    count++;
    bool update = false;
    //通常の最短経路探索
    if (count <= V - 1)
    {
      loop(i, E)
      {
        edge e = side[i];
        /*
      現在いる頂点の最短距離がinfでなく、
      かつ行先の最短距離が(現在いる頂点の最短距離+有向辺のコスト)よりも大きいとき更新
      */
        if (dist[e.from] != 1e18 && dist[e.to] > dist[e.from] + e.cost)
        {
          dist[e.to] = dist[e.from] + e.cost;
          update = true; //探索継続
        }
      }
    }
    //各頂点までに負閉路が存在するかチェック
    if (count >= V)
    {
      loop(i, E)
      {
        edge e = side[i];
        /*
      現在いる頂点の最短距離がinfでなく、
      かつ行先の最短距離が(現在いる頂点の最短距離+有向辺のコスト)よりも大きいとき更新
      +負閉路発見
      */
        if (dist[e.from] != 1e18 && dist[e.to] > dist[e.from] + e.cost)
        {
          dist[e.to] = dist[e.from] + e.cost;
          find_negative_loop[e.to] = true;
          update = true; //探索継続
        }
        //前(from)がtrueなら次(to)もtrue
        if (find_negative_loop[e.from])
          find_negative_loop[e.to] = true;
      }
    }
    if ((!update) || count == 2 * V - 1)
      break; //更新がなくなるか2*V-1回のwhileループが終了すれば終了
  }
}
int main()
{
  cin >> V >> E;
  side.resize(E);
  dist.resize(V);
  find_negative_loop.assign(V, false);
  loop(i, E)
  {
    ll a, b, c;
    cin >> a >> b >> c;
    side[i].from = a - 1;
    side[i].to = b - 1;
    side[i].cost = (-1) * c;
  }
  bellman_ford(0);
  ll ans = (-1) * dist[V - 1];
  if (find_negative_loop[V - 1])
    putout("inf");
  else
    putout(ans);
  return 0;
}