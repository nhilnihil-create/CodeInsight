#include <bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
#define ll long long
#define ld long double
#define lint __int128
#define vi vector<int>
#define pb push_back
#define lp(i,a,b) for(int i = a ; i <= b ; i ++)
#define rlp(i,a,b) for(int i = b ; i >= a ; i --)
#define a_sort(v) sort(v.begin(), v.end())
#define d_sort(v) sort(v.rbegin(), v.rend())
#define pii pair<int,int>
#define pi 3.14159265358979323846264338327950
using namespace std ;
// #define debug

const int MOD = 1E9 + 7 ;
const int N = 1E5 ;

int main() {
    #ifdef debug
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    #endif // debug
    optimize

    string a , b ; cin >> a >> b ;
    if(a.size() > b.size()) cout << "GREATER\n" ;
    else if(a.size() < b.size()) cout << "LESS\n" ;
    else {
        if(a > b) cout << "GREATER\n" ;
        else if(a < b) cout << "LESS\n" ;
        else cout << "EQUAL\n" ;
    }
}
