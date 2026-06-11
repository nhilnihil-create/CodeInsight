#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
 
using tpl = tuple<int, int, int>;
typedef pair<int,int> pii;

void fastStream(){cin.tie(0);std::ios_base::sync_with_stdio(0);}

int W, H;
int P[100010];
int Q[100010];
int main(){

    cin >> W >> H;
    for(int i = 0; i < W; i++) cin >> P[i];
    for(int i = 0; i < H; i++) cin >> Q[i];
    int col = 0;
    int row = 0;
    vector<pii> v;
    for(int i = 0; i < W; i++){
        v.push_back(pii(P[i], 0));
    }
    for(int i = 0; i < H; i++){
        v.push_back(pii(Q[i], 1));
    }
    sort(v.begin(), v.end());
    ll ans = 0;
    for(pii p : v){
        if(p.second == 0){
            ans += (ll)(1 + H - row) * p.first;
            col++;
        }
        else{
            ans += (ll)(1 + W - col) * p.first;
            row++;
        }
    }
    cout << ans << endl;

    return 0;
}
