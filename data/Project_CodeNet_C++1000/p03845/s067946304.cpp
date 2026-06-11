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

    int n, m;
    cin >> n;
    vi t(n);
    fo(i, n) cin >> t[i];
    cin >> m;

    int p, x;
    fo(i, m) {
        cin >> p >> x;
        int soma = 0;
        fo(j, n) {
            if ( j == p - 1 ) soma += x;
            else soma += t[j];
        }
        cout << soma << endl;
    }

    return 0;
}