#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define PI 3.141592
#define LL_INF 9000000000000000000
#define LL_MINF -9000000000000000000
#define INT_INF 2000000000
#define INT_MINF -2000000000
#define all(a) (a).begin(), (a).end()
#define fi first
#define se second
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

int main(){
    int N, M;
    cin >> N >> M;
    vector<pair<ll, ll>> AB(N);
    for(int i = 0; i < N; i++) cin >> AB[i].fi >> AB[i].se;
    vector<pair<ll,ll>> CD(M);
    for(int i = 0; i < M; i++) cin >> CD[i].fi >> CD[i].se;
    for(int i = 0; i < N; i++){
        ll min_l = LL_INF;
        for(int j = 0; j < M; j++){
            min_l = min(min_l, abs(AB[i].fi - CD[j].fi) + abs(AB[i].se - CD[j].se));
        }
        for(int j = 0; j < M; j++){
            if(min_l == abs(AB[i].fi - CD[j].fi) + abs(AB[i].se - CD[j].se)){
                 cout << j + 1 << endl;
                 break;
            }
        }
    }
}
