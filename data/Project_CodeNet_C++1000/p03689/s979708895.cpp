#include<bits/stdc++.h>

using namespace std;
using ll = long long int;

int main(void) {
    constexpr ll MOD = 1e9 + 7;
    constexpr double PI = acos(-1);
    cout << fixed << setprecision(16);
    cin.tie(0); ios::sync_with_stdio(false);

    ll H, W, h, w;
    cin >> H >> W >> h >> w;

    vector<vector<ll>> imos(H+1, vector<ll>(W+1, 0));
    for(ll i=1; i<=H; i++)
        for(ll j=1; j<=W; j++)
            imos[i][j] = 3000*i*j;
    for(ll i=0; i+h<=H; i++)
    for(ll j=0; j+w<=W; j++) {
        // -1 = imos[i+h][j+w] + imos[i][j] - imos[i+h][j] - imos[i][j+w]
        imos[i+h][j+w] = imos[i+h][j] + imos[i][j+w] - imos[i][j] - 1;
    }

    vector<vector<ll>> res(H, vector<ll>(W, 1));

    for(ll i=0; i<H; i++)
        for(ll j=0; j<W; j++)
            res[i][j] = imos[i+1][j+1] + imos[i][j] - imos[i+1][j] - imos[i][j+1];

    if(imos[H][W] > 0) {
        cout << "Yes" << endl;
        for(ll i=0; i<H; i++, cout << endl)
            for(ll j=0; j<W; j++)
                cout << res[i][j] << ' ';
    } else
        cout << "No" << endl;
}
