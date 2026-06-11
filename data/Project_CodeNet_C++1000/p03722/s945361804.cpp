#include <iostream>
#include <vector>
#include <array>
#include <limits>

using namespace std;
typedef long long ll;

int main(){
    ll n, m;
    cin >> n >> m;
    vector<array<ll, 3>> edge(m);
    for(int i = 0; i < m; ++i){
        ll a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        edge.at(i).at(0) = a;
        edge.at(i).at(1) = b;
        edge.at(i).at(2) = c;
    }

    vector<ll> dist(n, numeric_limits<ll>::min());
    dist.at(0) = 0;
    for(int i = 0; i < n - 1; ++i){
        for(int j = 0; j < m; ++j){
            const ll a = edge.at(j).at(0);
            const ll b = edge.at(j).at(1);
            const ll c = edge.at(j).at(2);
            if(dist.at(a) != numeric_limits<ll>::min() &
               dist.at(b) < dist.at(a) + c){
                dist.at(b) = dist.at(a) + c;
            }
        }
    }

    vector<bool> cycle(n, false);
    for(int j = 0; j < m; ++j){
        const ll a = edge.at(j).at(0);
        const ll b = edge.at(j).at(1);
        const ll c = edge.at(j).at(2);
        if(dist.at(a) != numeric_limits<ll>::min() &
            dist.at(b) < dist.at(a) + c){
            cycle.at(b) = true;
        }
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            const ll a = edge.at(j).at(0);
            const ll b = edge.at(j).at(1);
            if(cycle.at(a)){
                cycle.at(b) = true;
            }
        }
    }

    if(cycle.at(n - 1)){
        cout << "inf" << endl;
    }else{
        cout << dist.at(n - 1) << endl;
    }
    return 0;
}
