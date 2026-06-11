#include <iostream>
#include <string>
using namespace std;

string s;
int n, mod = 1000000007;

long long mem[5042][5042];

long long solve ( int left, int ok ) {
    if ( left == 0 ) {
        if ( ok == s.size() ) { return 1; }
        return 0;
    }
    if ( mem[left][ok] ) { return mem[left][ok]-1; }
    long long ret = 0;

    ret += 2*solve( left-1, ok+1 );
    ret += solve ( left-1, max( ok-1, 0 ) );
    ret %= mod;

    mem[left][ok] = ret+1;
//    cout << left << " " << wrong << " " << ind << " : " <<
    return ret;
}
string getS ( int x ) {
    string ret = "";
    for ( int i = 0 ; i < x ; i ++ ) { ret += "1"; }
    return ret;
}
long long pow2( long long a, long long st ) {
    long long ret = 1;
    for ( ; st ; st /= 2 ) {
        if ( st&1 ) {
            ret *= a;
            ret %= mod;
        }
        a *= a;
        a %= mod;
    }
    return ret;
}

int main () {

    cin >> n;
    cin >> s;
    long long cans = solve ( n, 0 );
    for ( int i = 0 ; i < s.size() ; i ++ ) {
        cans *= pow2( 2, mod-2 );
        cans %= mod;
    }
    cout << cans << "\n";

    return 0;
}
