#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    for (long long i=3*A;i<10000000; i+=A){
        if (i%B==C){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}