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
#define all(x) x.begin(), x.end()
#define fo(i, n) for( int i = 0; i < n; i++ )


int main() {

    int n, k;
    cin >> n >> k;
    vi x(n + 1);

    fo(i, n) cin >> x[i + 1];

    int covered = 0;

    fo(i, n) {
        covered += min(2 * abs(x[i + 1]), 2 * abs(x[i + 1] - k));
    }

    cout << covered << endl;

    return 0;
}