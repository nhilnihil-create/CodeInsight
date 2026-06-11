#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
#include <iterator>
#include <map>
#include <set>
#include <iomanip>
#include <vector>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using Graph = vector<vector<int>>;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
#define INF 100000000000
#define MAX 200001
#define MOD 1000000007  

int main(){
    int W, H;
    cin >> W >> H;
    vector<ll> P(W), Q(H);
    for(int i = 0; i < W; i++) cin >> P[i];
    for(int i = 0; i < H; i++) cin >> Q[i];
    sort(P.begin(), P.end());
    vector<ll> P_acc(W);
    P_acc[0] = P[0];
    for(int i = 1; i < W; i++){
        P_acc[i] = P_acc[i - 1] + P[i];
    }
    ll ans = P_acc[W - 1];
    for(int i = 0; i < H; i++){
        if(Q[i] < P[0]) ans += Q[i] * (W + 1);
        else{
            auto iter = upper_bound(P.begin(), P.end(), Q[i]);
            ll idx = iter - P.begin();
            idx--;
            ans += P_acc[idx];
            ans += Q[i] * (W - idx);
        }
    }
    cout << ans << endl;
}