#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <utility>
#include <map>
#include <functional>
typedef long long ll;
using namespace std;
const int MOD = 1000000007;
const ll INF = 1000000000;
int main(){
    int n,m,r;
    cin >> n >> m >> r;

    vector<int> city(r);
    for(int i = 0;i < r;i++){
        cin >> city[i];
        city[i]--;
    }

    sort(city.begin(),city.end());

    vector<vector<ll>> d(n,vector<ll>(n,INF));
    for(int i = 0;i < m;i++){
        ll a,b,c;
        cin >> a >> b >> c;
        a--,b--;
        d[a][b] = c;
        d[b][a] = c;
    }
    for(int k = 0;k < n;k++){
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }

    ll ans = INF;
    do{
        ll now = 0;
        for(int i = 0;i < r-1;i++){
            now += d[city[i]][city[i+1]];
        }
        ans = min(ans,now);
    }while(next_permutation(city.begin(),city.end())); 


    cout << ans << endl;
}
