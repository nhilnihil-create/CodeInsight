#include <iostream>
#include <vector>
using namespace std;

int main() {

    long long K;
    cin >> K;


    int N = 50, r = K % N;
    long long a[50];
    for(int i = 0; i < N; i++) {
        if(i < r) a[i] = K / N + N * 2 - r;
        else a[i] = K / N + N - r - 1;
    }

    cout << N << endl;
    for(int i = 0; i < N - 1; i++) {
        cout << a[i] << " ";
    }
    cout << a[N - 1] << endl;
}
