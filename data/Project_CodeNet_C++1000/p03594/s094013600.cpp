#include "bits/stdc++.h"
using namespace std;
#define FOR(i,j,k) for(int (i)=(j);(i)<(int)(k);++(i))
#define rep(i,j) FOR(i,0,j)
#define each(x,y) for(auto &(x):(y))
#define mp make_pair
#define mt make_tuple
#define all(x) (x).begin(),(x).end()
#define debug(x) cout<<#x<<": "<<(x)<<endl
#define smax(x,y) (x)=max((x),(y))
#define smin(x,y) (x)=min((x),(y))
#define MEM(x,y) memset((x),(y),sizeof (x))
#define sz(x) (int)(x).size()
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

char col[2][3] = { "RY", "GB" };

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int H, W, d;
    cin >> H >> W >> d;

    vector<string> S(H, string(W, ' '));
    rep(y, H)rep(x, W) {
        int Y = x + y;
        int X = x - y;
        Y = Y % (2 * d) / d;
        X = X % (2 * d);
        if (X < 0)X += 2 * d;
        X /= d;
        S[y][x] = col[Y][X];
    }

    rep(y, H)cout << S[y] << endl;
}
