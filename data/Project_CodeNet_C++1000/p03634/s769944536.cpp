#include <bits/stdc++.h>
#define fi first
#define se second
#define m_p make_pair
#define p_b push_back
#define e_b emplace_back
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
using namespace std;
using ll = long long;
using ld = long double;
template<class T> bool chmax(T &a,T b){if(a<b){a=b;return true;}return false;}
template<class T> bool chmin(T &a,T b){if(a>b){a=b;return true;}return false;}

vector<ll> dis;
void dfs(vector<vector<pair<int,ll>>> &graph,int now,int pa){
  if(pa==-1)  dis.at(now)=0;
  for(int i=0;i<sz(graph.at(now));i++){
    int next_v=graph.at(now).at(i).fi;
    ll next_c=graph.at(now).at(i).se;
    if(next_v==pa)  continue;

    dis.at(next_v)=dis.at(now)+next_c;
    dfs(graph,next_v,now);
  }
}

int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int N;
  cin >> N;
  vector<vector<pair<int,ll>>> graph(N);
  for(int i=0;i<N-1;i++){
    int a,b,c;
    cin >> a >> b >> c;
    a--;
    b--;
    graph.at(a).p_b(m_p(b,c));
    graph.at(b).p_b(m_p(a,c));
  }

  int Q,K;
  cin >> Q >> K;
  K--;
  dis.resize(N,-1e9);
  dfs(graph,K,-1);
  for(int _=0;_<Q;_++){
    int x,y;
    cin >> x >> y;
    x--;
    y--;
    cout << dis.at(x)+dis.at(y) << endl;
  }

  return 0;
}