#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <tuple>
#include <bitset>
#include <random>
#define REP(i,n) for(int i=0;i<n;i++)
#define INF 1000000007
using namespace std;
using pii=pair<int,int>;


vector<int> Dijkstra(vector<vector<pii>> adj_list,int start){/*adj_listはs番目に「「tとsからtへの距離dのpair」を並べたベクトル」が入っているベクトル */
  int n=adj_list.size();
  /*初期化*/
  vector<int> distance(n,INF);
  vector<int> pre(n);
  distance.at(start)=0;
  priority_queue<pii,vector<pii>,greater<pii>> unsettled;/*未確定の頂点*/
  REP(u,n){
    unsettled.push(make_pair(distance.at(u),u));
  }

  /*本計算*/
  while(!unsettled.empty()){
    int u;
    tie(ignore,u)=unsettled.top();
    unsettled.pop();/*uを確定*/
    /*uから伸びている辺の先へ書き込み*/

    for(auto vpair : adj_list.at(u)){
      int weight_u_to_v,v;
      tie(v,weight_u_to_v)=vpair;
      int alt=distance.at(u)+weight_u_to_v;
      /*更新*/
      if(distance.at(v)>alt){
        distance.at(v)=alt;
        pre.at(v)=u;
        unsettled.push(make_pair(alt,v));

      }
    }

  }
  return pre;

}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> adj_list(n);
    vector<vector<bool>> is_unused(n,vector<bool>(n,false));/*(i,j)を結ぶ辺が使われたかどうか判定*/
    REP(i,m){
        int s,t,d;
        cin>>s>>t>>d;
        s--;
        t--;
        adj_list.at(s).push_back(make_pair(t,d));
        adj_list.at(t).push_back(make_pair(s,d));
        is_unused.at(s).at(t)=true;/*辺が存在*/
        is_unused.at(t).at(s)=true;
    }
    
    

    REP(i,n){
        REP(j,n){
            if(i<j){
                vector<int> pre;
                pre=Dijkstra(adj_list,i);
                is_unused.at(pre.at(j)).at(j)=false;
                is_unused.at(j).at(pre.at(j))=false;
            }
        }
    }
    int ans=0;
    REP(i,n){
        REP(j,n){
            if(i<j&&is_unused.at(i).at(j)){
                ans++;

            }
        }
    }
    cout<<ans<<endl;

}
  