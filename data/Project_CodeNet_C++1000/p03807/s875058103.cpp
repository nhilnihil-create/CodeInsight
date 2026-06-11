#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    long long A[N];
    for(int i = 0; i<N; i++) cin >> A[i];

    int kisu = 0;
    for(int i = 0; i<N; i++) {
        if(A[i] % 2 == 1)kisu++;
    }

    string res = "YES";
    if(kisu % 2 == 1) res = "NO";
    cout << res << endl;
    return 0;
}