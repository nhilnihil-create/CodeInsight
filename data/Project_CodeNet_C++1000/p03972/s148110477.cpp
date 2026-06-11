#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <random>
#include <chrono>
#include <queue>
#include <ctime>
#include <cassert>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
#define fs first
#define sc second
#define INF 1000000000
#define MOD 1000000007
#define EPS 0.00000001


int main() {
    int W, H; cin >> W >> H;
    vector<PII> E;
    for(int i=0; i<W; i++){
        int p; cin >> p;
        E.push_back({p, 0});
    }
    
    for(int i=0; i<H; i++){
        int q; cin >> q;
        E.push_back({q, 1});
    }

    sort(E.begin(), E.end());
    ll ans = 0;
    
    int w = W + 1;
    int h = H + 1;
    for(int i=0; i<W+H; i++){
        if(E[i].sc==0){
            ans += (ll)E[i].fs * h;
            w--;
        }
        else{
            ans += (ll)E[i].fs * w;
            h--;
        }
    }
    cout << ans << endl;
    return 0;
}
