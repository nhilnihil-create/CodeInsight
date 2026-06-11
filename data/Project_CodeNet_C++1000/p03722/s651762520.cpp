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
#define INF 100000000000000
using namespace std;
using pii=pair<int,int>;





vector<int64_t> dist;
vector<int> pre;
vector<bool> exist_negative_cycle;

void Bellman_Ford(vector<vector<pii>> adj_list,int start){
    /*trueなら負の閉路が存在*/
    
    int n=adj_list.size();
    /*初期化*/
    dist=vector<int64_t>(n,INF);
    pre=vector<int>(n);/*最短経路におけるひとつ前の頂点*/
    exist_negative_cycle=vector<bool>(n,false);/*nまでの経路に負の閉路があるかどうか*/
    dist.at(start)=0;
    REP(i,n){
        REP(u,n){
            for(auto vpair : adj_list.at(u)){
                int weight_u_to_v,v;
                tie(v,weight_u_to_v)=vpair;
                if(dist.at(v)>dist.at(u)+weight_u_to_v){
                  dist.at(v)=dist.at(u)+weight_u_to_v;
                  pre.at(v)=u;
                  if (i == n - 1){
                    exist_negative_cycle.at(v)=true;
                  }; // n回目にも更新があるなら負の閉路が存在
                }

            }
        }
    }


  
}
int main() {
  int V,E;
  cin>>V>>E;
  vector<vector<pair<int,int>>> adj_list(V);
  
  REP(i,E){
    int s,t,d;
    cin>>s>>t>>d;
    s--;
    t--;/*添字の調整*/
    adj_list.at(s).push_back(make_pair(t,-d));

  }
  

  Bellman_Ford(adj_list,0);
  
  if(exist_negative_cycle.at(V-1)){
    cout<<"inf"<<endl;
    return 0;
  }
  cout<<-dist.at(V-1)<<endl;


  return 0;
}