#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <climits>
#include <iomanip>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
struct edge{
    ll p;//点
    ll w;//辺の重み*-1
};
vector<vector<edge> > graph(100000);
vector<ll> res(100000);
ll v,e,r;//vは頂点,eは辺,rは始点
void dijkstra(){
  for(int i = 0;i < v;i++)res[i] = pow(10,18);
    res[r] = 0;
    priority_queue<pair<ll,ll> > que;//重み、頂点
    que.push(make_pair(0,r));
    while(!que.empty()){
        edge now;
        now.p = que.top().second;
        now.w = que.top().first * -1;
        que.pop();
        if(res[now.p] < now.w)continue;
        for(int i = 0;i < graph[now.p].size();i++){
            if(res[graph[now.p][i].p] > now.w + graph[now.p][i].w){
                res[graph[now.p][i].p] = now.w + graph[now.p][i].w;
                que.push(make_pair(res[graph[now.p][i].p] * -1,graph[now.p][i].p));
            }
        }
    }
}
int main(){
   ll kazu = 0;
   cin >> v >> e >> kazu;
   vector<ll> travel(kazu);
   for(int i = 0;i < kazu;i++){
     cin >> travel[i];
     travel[i]--;
   }
   sort(travel.begin(),travel.end());
    for(int i = 0;i < e;i++){
        ll a,b,c;
        cin >> a >> b >> c;//マイナスするか?気をつける
        a--,b--;
        edge memoa = {b,c};
        edge memob = {a,c};
        graph[a].push_back(memoa);
        graph[b].push_back(memob);//無向グラフのときはこれを追加
    }
  vector<vector<ll>> dis(v,vector<ll>(v));
  for(int i = 0;i < v;i++){
    r = i;
    dijkstra();
    for(int j = 0;j < v;j++)dis[i][j] = res[j];
  }
  //cout << dis[1][3] << " " << dis[3][2] << endl;
  ll resmin = 0;
  resmin = pow(10,18);
  //cout << "a" << endl;
  do{
    ll now = 0;
    for(int i = 0;i < kazu - 1;i++){
      now += dis[travel[i]][travel[i + 1]];
    }
    resmin = min(now,resmin);
    //if(now == 4)for(auto item:travel)cout << item << " ";
    //cout << endl;
    //if(travel[0] == 1 && travel[1] == 3 && travel[2] == 2)cout << now << endl;
    //cout << 1 << endl;
  }while(next_permutation(travel.begin(),travel.end()));
  cout << resmin << endl;
}