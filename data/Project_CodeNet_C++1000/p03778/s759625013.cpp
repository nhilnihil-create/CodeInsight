#include <bits/stdc++.h>
#define REP(i,n) for ( int i=0; i<int(n); i++ )
using namespace std;
typedef long long LL;


int main() {
    int w,a,b;
    cin >> w >> a >> b;
    if ( b>a+w||b+w<a ) {
        cout << min(abs(b-a-w),abs(a-b-w));
    } else {
        cout << 0 << '\n';
    }
    return 0;
}

 



