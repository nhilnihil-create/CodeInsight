#include <iostream>
#include <vector>
#include <climits>

using namespace std;
using ll=long long;
struct Edge{
    int a, b, c;
};
int main(){
    int n, m;
    cin >> n >> m;
    vector<ll> cost(n, LLONG_MIN);
    cost[0]=0;
    vector<Edge> edge(m);
    for(int i=0;i<m;++i){
        cin >> edge[i].a >> edge[i].b >> edge[i].c;
        --edge[i].a, --edge[i].b;
    }
    bool flag;
    int k;
    for(k=0;k<n;++k){
        flag=true;
        for(int i=0;i<m;++i){
            if(cost[edge[i].a]==LLONG_MIN)
                continue;
            if(cost[edge[i].b]<cost[edge[i].a]+edge[i].c){
                cost[edge[i].b]=cost[edge[i].a]+edge[i].c;
                flag=false;
            }
        }
        // for(int i=0;i<n;++i){
        //     cout << i << " " << cost[i] << endl;
        // }
        if(flag)
            break;
    }
    if(k==n && !flag){
        ll c = cost[n-1];
        for(int j=0;j<n;++j){
            for(int i=0;i<m;++i){
                if(cost[edge[i].a]==LLONG_MIN)
                    continue;
                if(cost[edge[i].b]<cost[edge[i].a]+edge[i].c){
                    cost[edge[i].b]=cost[edge[i].a]+edge[i].c;
                }
            }
        }
        if(c!=cost[n-1])
            cout << "inf";
        else
            cout << cost[n-1];
    }else{
        cout << cost[n-1];
    }
    return 0;
}