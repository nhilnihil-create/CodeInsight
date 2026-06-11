#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

const ll mod = 1000000007;

int main() {
    int N, M;
    cin >> N >> M;
    vector<pair<int, bool>> data(N, {1, false});
    data[0].second = true;

    rep(i, M){
        int x, y;
        cin >> x >> y;
        int numx = data[x - 1].first;
        bool bx = data[x - 1].second;
        int numy = data[y - 1].first;
        bool by = data[y - 1].second;
        
        if(numx == 1){
            data[x - 1] = make_pair(0, false);
            data[y - 1] = make_pair(numy + 1, by || bx);
        } else {
            data[x - 1] = make_pair(numx - 1, bx);
            data[y - 1] = make_pair(numy + 1, by || bx);
        }
    }

    int ans = 0;

    for(pair<int, bool> p: data){
        if(p.second){
            ans++;
        }
    }
    cout << ans << endl;
    
    return 0;
}
