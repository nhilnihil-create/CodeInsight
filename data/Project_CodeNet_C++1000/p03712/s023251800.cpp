#include <bits/stdc++.h>
using namespace std;
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define int long long
#define ld long double
#define fi first
#define se second
#define all(uiet) uiet.begin(),uiet.end()
#define read(UIET) for(int i = 0; i < n; ++i) cin >> UIET[i]
#define out(UIET) for(int i = 0; i < n; ++i) cout << UIET[i]
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define vpp vector<pair< int, int > >
#define pll pair<int , int >
#define ppll pair < pll , pll >
#define debug(n1) cout << n1 << endl
#define len(a) ((int) (a).size())
#define endl "\n"
#define mod 1000000007
const int INF=(1LL<<60)-1;
const int maxN = 87;
int32_t main(){
    SPEED;
    int h, w;
    cin >> h >> w;
    h += 2;
    w += 2;
    char mat[h][w];
    for(int i = 0; i < h; ++i){
        if(i == 0 || i == h - 1){
            for(int j = 0; j < w; ++j){
                mat[i][j] = '#';
            }
        }
    }
    for(int i = 0; i < w; ++i){
        if(i == 0 || i == w - 1){
            for(int j = 0; j < h; ++j){
                mat[j][i] = '#';
            }
        }
    }
    for(int i = 1; i < h - 1; ++i){
        for(int j = 1; j < w - 1; ++j){
            cin >> mat[i][j];
        }
    }
    for(int i = 0; i < h; ++i){
        for(int j = 0; j < w; ++j){
            cout << mat[i][j];
        }
        cout << endl;
    }
}