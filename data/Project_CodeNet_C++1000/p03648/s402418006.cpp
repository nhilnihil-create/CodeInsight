#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

long long K;

long long N = 50;

int main(){
    cin >> K;
    long long val = (K + N - 1) / N + (N - 1);
    long long N1 = val * N - N * (N - 1) - K;
    cout << N << endl;
    for(int i = 1;i <= N1;i++){
        printf("%lld%c", val + N1 - N - 1, i == N ? '\n' : ' ');
    }
    for(int i = N1 + 1;i <= N;i++){
        printf("%lld%c", val + N1, i == N ? '\n' : ' ');
    }
    return 0;
}
