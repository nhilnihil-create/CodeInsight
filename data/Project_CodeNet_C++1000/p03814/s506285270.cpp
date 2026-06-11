#include <bits/stdc++.h>
using namespace std;

#define sws ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define INFINITO 1000000000
#define ll long long
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define ff first
#define ss second
#define vvi vector<vi>
#define all(x) x.begin(), x.end()
#define fo(i, n) for( int i = 0; i < n; i++ )


int main() {

    string s;
    cin >> s;

    int primA = -1, ultZ = -1;
    fo(i, (int) s.size() ) {
        if ( s[i] ==  'A' ) {
            primA = i;
            break;
        }
    }
    for ( int i = s.size() - 1; i >= 0; i-- ) {
        if ( s[i] == 'Z' ) {
            ultZ = i;
            break;
        }
    }
    cout << ultZ - primA + 1 << endl;

    return 0;
}