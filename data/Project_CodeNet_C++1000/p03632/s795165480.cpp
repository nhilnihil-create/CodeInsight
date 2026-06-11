#include <bits/stdc++.h>
using namespace std;

int main(){
    int A, b, C, D;
    cin >> A >> b >> C >> D;
    if (A<=C&&D<=b) {
        cout << D-C << endl;
        return 0;
    }
    else if (C<A && b<D) {
        cout << b-A << endl;
        return 0;
    }
    else if ((b>C && D>b)||(A<C && C<b)) {
        cout << b-C << endl;
        return 0;
    }
    else if ((A<D && C<A)||(A<D && D<b)) {
        cout << D-A << endl;
        return 0;
    }
    else if (b<=C || D<=A) cout << 0 << endl;
}
