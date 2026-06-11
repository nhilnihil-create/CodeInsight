#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    int A,B,C,D;cin>>A>>B>>C>>D;
    if (B <= C || D <= A) cout << 0 << endl;
    else {
        cout << min(B,D) - max(A,C) << endl;
    }
    return 0;
}