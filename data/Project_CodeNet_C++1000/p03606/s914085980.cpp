#include <bits/stdc++.h>
using namespace std;

int main() {

    int N,li,ri,sn;
    cin >> N;

    sn = 0;

    for(int i = 0; i < N; i++){
        cin >> li >> ri;
        sn += ri - li + 1;
    }

    cout << sn;
}