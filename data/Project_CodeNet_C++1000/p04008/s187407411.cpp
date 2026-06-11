#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

ll N, K;
ll to[101010];
ll from[101010];
ll depth[101010];
ll ans = 0;



int main(){

    cin >> N >> K;
    cin >> to[1];
    if(to[1] != 1)ans++;
    for(ll i = 2; i <= N; i++){
        cin >> to[i];
        from[to[i]]++;
    }
    queue<ll>Q;
    for(ll i = 1; i <= N; i++){
        if(from[i] == 0){
            Q.push(i);
        }
    }
    while(!Q.empty()){
        ll idx = Q.front();
        Q.pop();
        if(idx == 1)break;
        if(depth[idx] + 1 == K && to[idx] != 1){
            ans++;
        }
        else if(to[idx] != 1){
            depth[to[idx]] = max(depth[to[idx]], 1 + depth[idx]);
        }
        from[to[idx]]--;
        if(from[to[idx]] == 0)Q.push(to[idx]);    
    }
    cout << ans << endl;

    return 0;
}