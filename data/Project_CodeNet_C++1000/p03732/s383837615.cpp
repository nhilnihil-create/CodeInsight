#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <map>
#define ll long long
using namespace std;
using p = pair<ll, ll>;
ll dx[4] = {-1, 0, 1, 0};
ll dy[4] = {0, 1, 0, -1};

int main(){
    ll n, w;
    cin >> n >> w;
    vector<p> vp;
    for(ll i = 0; i < n; i++){
        ll a, b;
        cin >> a >> b;
        vp.push_back(p(a, b));
    }
    sort(vp.begin(), vp.end());
    ll count = 0;
    vector<vector<ll>> g(4), sum(4);
    for(ll i = 0; i < n; i++){
        ll a = vp[i].first, b = vp[i].second;
        g[count].push_back(b);
        if(a!=vp[i+1].first) count++;
    }
    sort(g[0].begin(), g[0].end(), greater<ll>());
    sort(g[1].begin(), g[1].end(), greater<ll>());
    sort(g[2].begin(), g[2].end(), greater<ll>());
    sort(g[3].begin(), g[3].end(), greater<ll>());
    //sum[0].push_back(0);sum[1].push_back(0);
    //sum[2].push_back(0);sum[3].push_back(0);
    for(ll i = 0; i < 4; i++){
        sum[i].push_back(0);
        for(ll j = 0; j < g[i].size(); j++){
            ll d = sum[i][sum[i].size()-1];
            ll e = g[i][j];
            sum[i].push_back(d+e);
            //cout << sum[i][sum[i].size()-1] << " ";
        }
        //cout << endl;
    }
    /*for(ll i = 0; i < 4; i++){
        for(ll j = 0; j < sum[i].size(); j++){
            cout << sum[i][j] << " ";
        }
        cout << endl;
    }*/
    ll minw = vp[0].first;
    ll MAX = 0;
    for(ll i = 0; i < sum[0].size(); i++){
        for(ll j = 0; j < sum[1].size(); j++){
            for(ll k = 0; k < sum[2].size(); k++){
                for(ll l = 0; l < sum[3].size(); l++){
                    if(w >= minw*i+(minw+1)*j+(minw+2)*k+(minw+3)*l){
                        MAX = max(sum[0][i]+sum[1][j]+sum[2][k]+sum[3][l], MAX);
                       //cout << minw*i+(minw+1)*j+(minw+2)*k+(minw+3)*l << endl;
                    }
                }
            }
        }
    }
    cout << MAX << endl;
    return 0;
}
