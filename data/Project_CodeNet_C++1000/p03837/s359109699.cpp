#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;
using ll = long long;
using ld = long double;

#define fi first
#define se second
#define m_p make_pair
#define p_b push_back
#define e_b emplace_back
#define all(x) (x).begin(),(x).end()
#define uniq(x) ((x).erase(unique(all(x)),(x).end()))
#define sz(x) ((int)(x).size())

#define REP(i,m,n) for(int i=(int)(m);i<(int)(n);i++)
#define rep(i,n) REP(i,0,n)

string to_string(string s){
  return '"' + s + '"';
}
string to_string(const char *s){
  return to_string((string)s);
}
string to_string(bool b){
  return (b ? "true" : "false");
}
template<class A, class B>
string to_string(pair<A, B> p){
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template<class A, class B, class C>
string to_string(tuple<A, B, C> p){
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}
template<class A, class B, class C, class D>
string to_string(tuple<A, B, C, D> p){
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}
template<class A>
string to_string(A v){
  bool first = true;
  string res = "{";
  for(const auto &x : v){
    if(!first){
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
void debug_out(){cerr << endl;}
template<class Head, class... Tail>
void debug_out(Head H, Tail... T){
  cerr << " " << to_string(H);
  debug_out(T...);
}
#ifdef LOCAL//compile with -DLOCAL
#define debug(...) cerr << "LINE" << __LINE__ << " [" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) void(0)
#endif

template<class T> bool chmax(T &a,T b){if(a<b){a=b;return true;}return false;}
template<class T> bool chmin(T &a,T b){if(a>b){a=b;return true;}return false;}


int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int N,M;
  cin >> N >> M;
  vector<pair<pair<int,int>,int>> abc(M);
  vector<vector<pair<int,int>>> graph(N);
  rep(i,M){
    int a,b,c;
    cin >> a >> b >> c;
    a--;
    b--;
    abc.at(i) = m_p(m_p(a,b),c);
    graph.at(a).p_b(m_p(b,c));
    graph.at(b).p_b(m_p(a,c));
  }

  vector<bool> used(M,false);
  rep(i,N){
    vector<int> dist(N,1e9);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    dist.at(i) = 0;
    pq.push(m_p(0,i));
    while(!pq.empty()){
      int cost = pq.top().fi;
      int v = pq.top().se;
      pq.pop();
      if(dist.at(v) < cost) continue;
      rep(j,sz(graph.at(v))){
        int nv = graph.at(v).at(j).fi;
        int nc = cost + graph.at(v).at(j).se;
        if(dist.at(nv) <= nc) continue;
        dist.at(nv) = nc;
        pq.push(m_p(nc,nv));
      }
    }

    rep(j,M){
      int a = abc.at(j).fi.fi;
      int b = abc.at(j).fi.se;
      int c = abc.at(j).se;
      if(abs(dist.at(a) - dist.at(b)) == c) used.at(j) = true;
    }
  }

  int ans = 0;
  rep(i,M){
    if(!used.at(i)) ans++;
  }
  cout << ans << endl;

  return 0;
}