#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

const int INFTY = 2e9;

int main(){
    int N; cin >> N;
    vector<vector<ll> > cost(N, vector<ll>(N,INFTY));
    vector<vector<bool> > need(N, vector<bool>(N,true));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> cost[i][j];
        }
    }

    for(int k=0;k<N;k++){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(cost[i][j] > cost[i][k] + cost[k][j]){
                    cout << -1 << endl;
                    return 0;
                }

                if(cost[i][k] + cost[k][j] == cost[i][j] && cost[i][k] > 0 && cost[k][j] > 0){
                    need[i][j] = false;
                }
            }
        }
    }

    ll ans = 0ll;
    for(int i=0;i<N;i++){
        for(int j=i;j<N;j++){
            if(need[i][j]) ans += cost[i][j];
        }
    }
    cout << ans << endl;
    return 0;
}