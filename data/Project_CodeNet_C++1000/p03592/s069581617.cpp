#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

bool is_integer( double x ){
  return floor(x)==x;
}

int main(void){
    // input
    int N, M, K;
    cin >> N >> M >> K;

    // col : 行ボタンを押した回数
    // row : 列ボタンを押した回数
    // col を押して黒くなった目の個数 = (N - row) * col
    // row を押して黒くなった目の個数 = (M - col) * row

    for (int col = 0; col < M+1; ++col) {
        for (int row = 0; row < N+1; ++row) {
            int n = (N - row) * col + (M - col) * row;
            if (n == K) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}