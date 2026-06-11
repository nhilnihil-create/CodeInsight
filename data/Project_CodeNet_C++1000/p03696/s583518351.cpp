#include <iostream>
#include <string>
#define L '('
#define R ')'

int main(void) {
    using std::cin;
    using std::string;
    int n;
    cin >> n;
    string s;
    cin >> s;

    int nest   = 0;
    int need_l = 0;
    for (auto &se : s) {
        if (nest == 0 && se == R) {
            need_l++;
            nest++;
        }
        if (se == L)
            nest++;
        else
            nest--;
    }
    int need_r = nest;

    for (int i = 0; i < need_l; ++i) std::cout << L;
    std::cout << s;
    for (int i = 0; i < need_r; ++i) std::cout << R;
    std::cout << '\n';

    return 0;
}
