#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <set>
#include <map>
using namespace std;
struct edge{long long from ,to,cost;};
edge es[2005];

long long d[1005];
int V, E;
int N, M;
bool heiro = false;

void shortest_path(int s){
    for(int i=0;i<V;i++){
        d[i] = -1000000000000000005;
    }
    d[s] = 0;
    for(int i=0;i<V;i++){
        bool update = false;
        for (int j=0;j<E;j++){
            edge e = es[j];
            if(d[e.from] != -1000000000000000005 && d[e.to]<d[e.from]+e.cost){
                d[e.to] = d[e.from] +e.cost;
                update = true;
            }
        }
        if(!update){
            break;
        }
        if(i==V-1){
            heiro = true;
        }
    }
    
}
int main(){
    cin >> N >> M;
    V = N;
    E = M;
    for(int i=0;i<M;i++){
        long long a,b,c;
        cin >> a >> b >> c;
        es[i] = edge({a-1,b-1,c});
    }
    shortest_path(0);
    if(heiro){
        bool heiroN = false;
        long long c = d[N-1];
        for(int i=0;i<V;i++){
            for (int j=0;j<E;j++){
                edge e = es[j];
                if(d[e.from] != -1000000000000000005 && d[e.to]<d[e.from]+e.cost){
                    d[e.to] = d[e.from] +e.cost;
                }
            }
            if(c != d[N-1]){
                heiroN = true;
            }
        }
        if(heiroN){
        cout << "inf" << endl;
        return 0;
        } else {
            cout << d[N-1] << endl;
            return 0;
        }
    }
    cout << d[N-1] << endl;
    
}
