#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define PI 3.141592
#define MOD 1000000007
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
    int N;
    cin >> N;

    int sum =0;
    map<int, int> PT;
    for(int i = 1; i <= N; i++){
        int T;
        cin >> T;
        sum+= T;
        PT[i] = T;
    }
    int M;
    cin >> M;
    vector<pair<int ,int>> PX(M);
    for(int i = 0; i < M; i++){
        cin >> PX[i].fi >> PX[i].se;
    }
    for(auto px : PX){
        cout << sum - (PT[px.fi] - px.se) << endl;
    }
}
