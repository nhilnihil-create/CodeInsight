#include <bits/stdc++.h>
using namespace std;

#define DUMP(x) cerr << #x << "=" << x << endl
#define DUMP2(x, y) cerr<<"("<<#x<<", "<<#y<<") = ("<<x<<", "<<y<<")"<< endl
#define BINARY(x) static_cast<bitset<16> >(x)

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,m,n) for (int i=m;i<(int)(n);i++)

#define in_range(x, y, w, h) (0<=(int)(x) && (int)(x)<(int)(w) && 0<=(int)(y) && (int)(y)<(int)(h))
#define ALL(a) (a).begin(),(a).end()

typedef long long ll;
const int INF   = 1e9;
const ll  INFLL = 1e18;
typedef pair<int, int> PII;
int dx[4]={0, -1, 1, 0}, dy[4]={-1, 0, 0, 1};
int dx2[2] = {-1, 1}, dy2[2] = {1, -1};

typedef vector<vector<int>> Graph;
Graph G;
int H, W, D;

int main()
{
    ios::sync_with_stdio(false);
    cin >> H >> W >> D;

    vector<vector<int>> done(H, vector<int>(W));
    G.resize(H*W);

    char color[2][2] = {{'R', 'G'}, {'B', 'Y'}};

    rep(y, H) {
        rep(x, W) {
            int xx = x - y + H;
            int yy = x + y;

            cout << color[(xx / D) % 2][(yy / D) % 2];
        }
        cout << endl;
    }
}