#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < n; i++)

typedef long long ll;
using namespace std;
int mod = 1000000007;

int main(void){
    int W, H; cin >> W >> H;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    rep(i, W){
        ll a; cin >> a;
        pq.push(make_pair(a, 0));
    }
    rep(i, H){
        ll a; cin >> a;
        pq.push(make_pair(a, 1));
    }
    //(W+1)*(H+1)-1本の辺を引く
    //W+H回選ぶ
    ll ans = 0;
    int loop = W+H;
    rep(i, loop){
        ll val = pq.top().first;
        int which = pq.top().second;
        //cout << "val: " << val << ", which: " << which << endl;
        if(which){
            ans += val*(W+1);
            H--;
        }
        else{
            ans += val*(H+1);
            W--;
        }
        pq.pop();
    }
    cout << ans << endl;
    return 0;
}