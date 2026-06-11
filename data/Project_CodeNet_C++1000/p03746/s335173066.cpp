#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

template<typename CostType>
/// \brief 辺の情報
struct Edge{
  int      to;
  CostType cost;

  Edge(int t, CostType c): to(t), cost(c){
  }
};

template<typename CostType>
class Graph{

private:

  /// \brief adjacent_list_[n]=ノードnの隣接リストを表すvector<Edge>
  std::vector<std::vector<Edge<CostType>>> adjacent_list_;

public:

  /// \brief 頂点数
  const int NODE_SIZE_;

  /// \brief コンストラクタ
  /// \param node_size 頂点数
  explicit Graph(const int node_size): NODE_SIZE_(node_size),
                                       adjacent_list_(node_size){
  }

  /// \brief 有向グラフの辺を生やす
  /// \param from 辺の根本の頂点の番号
  /// \param to 辺の先の頂点の番号
  /// \param cost 辺のコスト
  void SetDirectedEdge(const int from, const int to, const CostType cost){
    adjacent_list_[from].push_back(Edge<CostType>(to, cost));
  }

  /// \brief 無向グラフの辺を生やす
  /// \param node_a 一方の頂点の番号
  /// \param node_b もう一方の頂点の番号
  /// \param cost 辺のコスト
  void
  SetUndirectedEdge(const int node_a, const int node_b, const CostType cost){
    SetDirectedEdge(node_a, node_b, cost);
    SetDirectedEdge(node_b, node_a, cost);
  }

  /// \brief ある頂点の隣接リストを取得
  /// \param node_num 頂点の番号
  /// \return 隣接リスト
  std::vector<Edge<CostType>> GetAdjacentList(int node_num) const{
    return adjacent_list_[node_num];
  }
};

using namespace std;



int main(void) {
  cout << std::fixed << std::setprecision(10);
  cin.tie(0);
  std::ios::sync_with_stdio(false);

  int n,m;
  cin>>n>>m;
  Graph<int> graph(n+1);
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    graph.SetUndirectedEdge(a,b,1);
  }

  vector<int> path;
  vector<bool> visited(n+1,false);
  vector<int> prev_node(n+1);
  int start_node=1;

  int current_node=start_node;
  while(true){
    visited[current_node]=true;
    bool found_next=false;
    for(auto e:graph.GetAdjacentList(current_node)){
      if(!visited[e.to]){
        found_next=true;
        prev_node[e.to]=current_node;
        current_node=e.to;
        break;
      }
    }
    if(!found_next){
      int backtrack=current_node;
      while(true){
        if(backtrack==start_node) break;
        path.push_back(backtrack);

        backtrack=prev_node[backtrack];
      }

      break;
    }
  }

  current_node=start_node;
  while(true){
    visited[current_node]=true;
    path.push_back(current_node);
    bool found_next=false;
    for(auto e:graph.GetAdjacentList(current_node)){
      if(!visited[e.to]){
        found_next=true;
        current_node=e.to;
        break;
      }
    }
    if(!found_next){
      break;
    }
  }

  cout<<path.size()<<endl;
  for(int i=0;i<path.size()-1;i++){
    cout<<path[i]<<" ";
  }
  cout<<path.back()<<endl;




  return 0;
}
