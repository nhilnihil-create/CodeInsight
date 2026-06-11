#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1e5+5;
int n;
ll A[N],B[N],C[N];
// +-+-+-
ll solve1() {
    ll res=0;
    if ( A[0]<=0 ) {
        res+=1-A[0];
        B[0]=1;
    } else {
        B[0]=A[0];
    }
    for ( int i=1; i<n; i++ ) {
        if ( i%2 ) { // -
            if ( B[i-1]+A[i]>=0 ) {
                res+=abs(-1-(B[i-1]+A[i]));
                B[i]=-1;
            } else {
                B[i]=B[i-1]+A[i];
            }
        } else { // +
            if ( B[i-1]+A[i]<=0 ) {
                res+=abs(1-(B[i-1]+A[i]));
                B[i]=1;
            } else {
                B[i]=B[i-1]+A[i];
            }
        }
    }
    return res;
}
// -+-+-+
ll solve2() {
    ll res=0;
    if ( A[0]>=0 ) {
        res+=abs(-1-A[0]);
        B[0]=-1;
    } else {
        B[0]=A[0];
    }
    for ( int i=1; i<n; i++ ) {
        if ( i%2==0 ) { // -
            if ( B[i-1]+A[i]>=0 ) {
                res+=abs(-1-(B[i-1]+A[i]));
                B[i]=-1;
            } else {
                B[i]=B[i-1]+A[i];
            }
        } else { // +
            if ( B[i-1]+A[i]<=0 ) {
                res+=abs(1-(B[i-1]+A[i]));
                B[i]=1;
            } else {
                B[i]=B[i-1]+A[i];
            }
        }
    }
    return res;
}

int main() {
    cin >> n;
    for ( int i=0; i<n; i++ ) {
        cin >> A[i];
    }
    cout << min(solve1(),solve2()) << '\n';
    return 0;
}