#include <iostream>
#include <vector>
#include <algorithm>

int N;
std::vector<std::vector<int>> Child;

int Height(int n) {
    int len = Child[n].size();
    if (len == 0)return 0;

    std::vector<int> ar;
    ar.resize(len);
    for (int i = 0; i < len; ++i) {
        ar[i] = Height(Child[n][i]);
    }

    std::sort(ar.begin(), ar.end());

    int result = -1;

    for (int j = 0; j < len; ++j) {
        result = std::max(result, ar[j] + len - j);
    }

    return result;
}

int main() {
    std::cin >> N;
    Child.resize(N);
    for (int i = 1; i < N; ++i) {
        int a;
        std::cin >> a;
        Child[a - 1].push_back(i);
    }
    std::cout << Height(0) << std::endl;
}