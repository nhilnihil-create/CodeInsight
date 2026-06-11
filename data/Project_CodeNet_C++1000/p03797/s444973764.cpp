#include <bits/stdc++.h>
using namespace std;

int main(void) {
    uint64_t N,M;
    uint64_t s,c;
    cin >> N >> M;

    if((N*2) < M){
        cout << N + ((M-(N*2)) / 4) << "\n";
    } else {
        cout << M/2 << "\n";
    }

    return 0;
}
