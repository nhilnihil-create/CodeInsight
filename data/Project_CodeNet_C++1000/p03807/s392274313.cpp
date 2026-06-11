#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,cnt=0;
    cin >> n;
    for ( int i=0; i<n; i++ ) {
        int a;
        cin >> a;
        cnt+=(a%2);
    }
    if ( cnt%2 ) puts("NO");
    else puts("YES");
    return 0;
}