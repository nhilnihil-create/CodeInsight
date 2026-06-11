#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int64_t K;
    cin >> K;

    int N = 50;
    vector<int64_t> a(N, N-1 + K/N);
    K %= N;
    for(int i=0; i<K; i++) {
        a[i] += N;
    }
    for(int i=0; i<N; i++) {
        a[i] -= K;
    }
    
    cout << N << endl;
    for(auto e: a) {
        cout << e << ' ';
    }
    return 0;
}
