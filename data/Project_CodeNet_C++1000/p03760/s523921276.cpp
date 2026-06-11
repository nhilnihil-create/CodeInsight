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

    string o, e;
    cin >> o >> e;
    fo(i, (int) max(o.size(), e.size())) {
        if ( i < (int) o.size() ) {
            cout << o[i];
        }
        if ( i < (int) e.size() ) {
            cout << e[i];
        }
    }
    cout << endl;

    return 0;
}