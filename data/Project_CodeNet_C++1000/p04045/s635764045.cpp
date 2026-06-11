#include <iostream>

int N, K, arr[10], tmp1, tmp2, tmp3;

bool checknot(int arr[], int n) {
    while (n > 0) {
        tmp3 = n % 10;
        if (arr[tmp3] != 0) {
            return false;
            break;
        }
        n /= 10;
    }
    return true;
}

void solve() {
    std::cin >> N >> K;
    tmp2 = N;
    for (int i=0; i<K; ++i) {
        std::cin >> tmp1;
        arr[tmp1] = 1;
    }
    
    while (1) {
        if (checknot(arr, tmp2)) {
            std::cout << tmp2 << std::endl;
            break;
        }
        ++tmp2;
    }
}

int main() {
    solve();
    return 0;
}