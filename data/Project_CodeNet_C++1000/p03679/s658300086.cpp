#include <iostream>

int main() {
    int x, a, b;
    std::cin >> x >> a >> b;
    int past = b - a;
    std::string res;
    if (past <= 0) res = "delicious";
    else if (past > x)res = "dangerous";
    else res = "safe";
    std::cout << res << std::endl;
}
