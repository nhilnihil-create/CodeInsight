#include<bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(ll i = 0; i < n; i++)
const ll INF = 1LL << 60;

int main(){
    ll N, K; cin >> N >> K;
    priority_queue<pair<ll, ll>> pq;
    rep(i, N){
        int a, b;
        cin >> a >> b;
        pq.push(make_pair(-1*a,b));
    }
    while(1){
        auto x = pq.top();
        pq.pop();
        K -= x.second;
        if(K <= 0){
            cout << -1 * x.first << endl;
            return 0;
        }
    }

    
} 