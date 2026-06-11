#include <bits/stdc++.h> 
using namespace std;
#define rep(i, N) for(int i=0; i<N; i++)
typedef long long ll;
#define dump(x) cerr<<#x<<"="<<x<<endl
using P = pair<int, int>;

int main() {
    int n, m, R;
    cin >> n >> m >> R;
    
    vector<vector<ll>> d(n+1, vector<ll>(n+1, 10000000));
    vector<int> r(R);
    rep(i, R) cin >> r.at(i);

    vector<vector<int>> g(n+1);
    vector<ll> dist(n+1, -1);
    vector<vector<ll>> d2(n+1, vector<ll>(n+1, 100000000));

    rep(i, m){
        int x, y; cin >> x >> y;
        ll c; cin >> c;
        d2.at(x).at(y) = min(d2.at(x).at(y), c);
        d2.at(y).at(x) = min(d2.at(y).at(x), c);
        g.at(x).push_back(y);
        g.at(y).push_back(x);
    }

    sort(r.begin(), r.end());
 /*
    queue<int> q;

    for(int i=1; i<=n; i++){
        dist.at(i) = 0;
        q.push(i);

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(auto v:g.at(u)){
                if(dist.at(v)!=-1) continue;
                dist.at(v) = dist.at(u) + d.at(u).at(v); 
                d2.at(u).at(v) = dist.at(v);
                q.push(v);
            }
        }

        for(int j=1; j<=n; j++){
            dist.at(j) = -1;
        } 
    }
*/
    for(int i=1; i<=n; i++){
        d2.at(i).at(i) = 0;
    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                d2.at(i).at(j) = min(d2.at(i).at(j), d2.at(i).at(k) + d2.at(k).at(j));
            }
        }
    }

    ll ans = 1000000000; 
    do{
        ll tmp = 0;
        for(int i=0; i<R-1; i++){
            tmp += d2.at(r.at(i)).at(r.at(i+1)); 
            dump(r.at(i));
        }
        ans = min(ans, tmp);
    }while(next_permutation(r.begin(), r.end()));

    cout << ans << endl;

    return 0;
}
