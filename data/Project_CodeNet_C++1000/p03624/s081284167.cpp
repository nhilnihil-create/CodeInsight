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

    string s;
    set<char> letras;
    cin >> s;

    for ( auto l : s ) letras.insert(l);

    for (char i = 'a'; i <= 'z'; i++ ) {
        if ( letras.find(i) == letras.end() ) {
            cout << i << endl;
            return 0;
        }
    }
    cout << "None\n";

    return 0;
}