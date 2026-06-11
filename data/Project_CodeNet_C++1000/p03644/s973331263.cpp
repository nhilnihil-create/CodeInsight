#include <iostream>

int main() {
    int N;
    std::cin >> N;

    int max_count = 0;
    int ans = 1;
    for (int i = 1; i <= N; i++) {
        int j = i;
        int count = 0;
        while (true) {
            if (j == 0 || j % 2 == 1) {
                break;
            }
            j /= 2;
            count++;
        }

        if (count > max_count) {
            max_count = count;
            ans = i;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}