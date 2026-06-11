#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000

char inv[127];
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    string S; cin >> S;
    inv['S'] = 'W';
    inv['W'] = 'S';
    rep(bit, 4) {
        string T = "";
        if (bit & 1) T += 'S';
        else T += 'W';
        if (bit & 2) T += 'S';
        else T += 'W';
        rep(i, n) {
            if (S[(i + 1) % n] == 'o' && T[i + 1] == 'S') T += T[i];
            if (S[(i + 1) % n] == 'x' && T[i + 1] == 'S') T += inv[T[i]];
            if (S[(i + 1) % n] == 'o' && T[i + 1] == 'W') T += inv[T[i]];
            if (S[(i + 1) % n] == 'x' && T[i + 1] == 'W') T += T[i];
        }
        //cout << T << endl;
        if(T[0] == T[n] && T[1] == T[n + 1]) {
            T.pop_back();T.pop_back();
            cout << T << endl;
            return 0;
        }
    }
    cout << -1 << endl;

    return 0;
}
//  ooxoox
// SWWSSSSW