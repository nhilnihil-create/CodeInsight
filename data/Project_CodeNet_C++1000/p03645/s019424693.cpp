#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 1e9
#define ALL(v) v.begin(), v.end()

using namespace std;
typedef unsigned long long ll;

int main(){
    ll n, m;
    cin >> n >> m;

    ll first, second;

    set<ll>oneNeighbors;
    set<ll>nNeighbors;

    REP(i, m){
        cin >> first >> second;
        if (first == 1) oneNeighbors.insert(second);
        if (second == n) nNeighbors.insert(first);
    }
    set<ll> intersect;
    set_intersection(nNeighbors.begin(),nNeighbors.end(),oneNeighbors.begin(),oneNeighbors.end(),
                  std::inserter(intersect,intersect.begin()));
    
    if (intersect.empty()){
        cout << "IMPOSSIBLE" << endl;
    }
    else{
        cout << "POSSIBLE" << endl;
    }
    
}