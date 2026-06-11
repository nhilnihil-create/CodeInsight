#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> i_i;
typedef pair<ll, ll> l_l;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;

int main() {
    //cout.precision(10);
    int h, w, d;
    cin >> h >> w >> d;
    char field[505][505];
    char buf[2][2];
    buf[0][0] = 'R';
    buf[0][1] = 'Y';
    buf[1][0] = 'G';
    buf[1][1] = 'B';
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            int MI = i + j;
            int MJ = i - j;
            MI = (MI + d) / d;
            MJ = (MJ + d * w) / d;
            field[i][j] = buf[MI % 2][MJ % 2];
            cout << field[i][j];
        }
        cout << endl;
    }
    return 0;
}
