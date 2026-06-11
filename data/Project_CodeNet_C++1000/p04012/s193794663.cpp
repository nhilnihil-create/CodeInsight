#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    string w; cin >> w;
    for (int i = 0; i < w.length(); ++i) {
        int cnt = 0;
        for (int j = 0; j < w.length(); ++j) {
            if (w[i] == w[j]) cnt++;
        }
        if (cnt % 2 != 0) {
            printf("%s\n", "No");
            return 0;
        }
    }
    printf("%s\n", "Yes");
    return 0;
}
