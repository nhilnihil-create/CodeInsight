#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define LIMIT1 200010
#define INF (1<<29)
#define LLINF (1LL<<60)
typedef long long ll;
#define rep(i,n) for((i)=0;(i)<(n);(i)++)
const ll MAX_E = LIMIT1;
const ll MAX_V = LIMIT1;

struct edge { ll from,to,cost; };
edge es[MAX_E];

ll d[MAX_V];
int V,E;

bool negative[LIMIT1];

void shortest_path(int s){
    for(int i=0;i<V;i++){
        d[i]=LLINF;
        negative[i]=false;
    }
    d[s] = 0;
    for(int loop=0;loop<V-1;loop++){
        for(int i=0;i<E;i++){
            edge e=es[i];
            if(d[e.from] != LLINF && d[e.to] > d[e.from]+e.cost){
                d[e.to] = d[e.from] + e.cost;
            }
        }
    }
}
bool find_negative_loop(){
  for(int i=0;i<V;i++) negative[i]=false;
  for(int loop=0;loop<V;loop++){
    for(int i=0;i<E;i++){
      if(d[es[i].from] == LLINF) continue;
      
      if(d[es[i].to] > d[es[i].from] + es[i].cost){
        d[es[i].to] = d[es[i].from] + es[i].cost;
        negative[es[i].to] = true;
      }
      if(negative[es[i].from]==true){
        negative[es[i].to] = true;
      }
    }
  }
  return negative[V-1];
}

int main(){
    int i,j;
    ll result=0;
    cin >> V >> E;
    rep(i,E){
        cin >> es[i].from >> es[i].to >> es[i].cost;
        es[i].from--;
        es[i].to--;
        es[i].cost *= -1;
    }
    shortest_path(0);
    result = -d[V-1];
    if(find_negative_loop()){
      cout << "inf" << endl;
      return 0;
    }
    cout << result << endl;
    
    return 0;
}