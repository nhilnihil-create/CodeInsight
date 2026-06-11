#include <bits/stdc++.h>
using namespace std;

int main() {
    long long K;
    cin >> K;
    
    long long N = 50;
    cout << N << endl;
    for(int i=0; i<N; ++i) {
        cout << (i - (K % N) + N + 1) % (N + 1) + (K / N) << (i + 1 == N ? '\n' : ' ');
    }    
}