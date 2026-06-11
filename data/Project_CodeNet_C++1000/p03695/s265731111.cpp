#include <bits/stdc++.h>
using namespace std;

#define sws ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
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

const int INF = 1e9;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;


int main() {

    int n;
    cin >> n;

    set<string> cores;
    int cont3200 = 0;
    vector<string> ratings = {"gray", "brown", "green", "cyan", "blue", "yellow", "orange", "red"};
    fo(i, n) {
        int a;
        cin >> a;
        a /= 400;
        if ( a >= 3200 / 400 ) cont3200++;
        else cores.insert(ratings[a]);
    }

    cout << max(1, (int) cores.size()) << " " << (int) cores.size() + cont3200 << endl;

    return 0;
}