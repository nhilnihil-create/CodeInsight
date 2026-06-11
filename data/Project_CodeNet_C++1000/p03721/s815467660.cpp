#include <bits/stdc++.h>
using namespace std;

int main() {
    map<int,long long> mp;
    int n;
    long long k;
    cin >> n >> k;
    for ( int i=0; i<n; i++ ) {
        int a,b;
        cin >> a >> b;
        mp[a]+=b;
    }
    for ( auto p:mp ) {
        if ( p.second>=k ) {
            cout << p.first << '\n';
            break;
        }
        k-=p.second;
    }

    return 0;
}
