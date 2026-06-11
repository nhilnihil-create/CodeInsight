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

    ll a, b;
    cin >> a >> b;

    if ( a > 0 ) cout << "Positive\n";
    // else if ( b >= 0 or a == 0 ) cout << "Zero\n";
    else if ( b < 0 ) cout << ((b - a + 1) & 1 ? "Negative\n" : "Positive\n");
    else cout << "Zero\n";

    return 0;
}