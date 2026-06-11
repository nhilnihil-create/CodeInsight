#include <iostream>
#include <vector>

using namespace std;
int main() {
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    vector<long double> suger;
    vector<long double> water;
    for (int i = 0; i * a <= f; i += 100) {
        for (int j = 0; j * b <= f; j += 100) {
            if (i * a + j * b > f)break;
            water.push_back(i * a + j * b);
        }
    }
    for (int i = 0; i * c <= f; i++) {
        for (int j = 0; j * d <= f; j++) {
            if (i * c + j * d > f)break;
            suger.push_back(i * c + j * d);
        }
    }
    long double ma = -1;
    int ansW;
    int ansS;
    for (auto w:water) {
        for (auto s:suger) {
            if (w + s <= f && w / 100 * e >= s) {
                if (ma < s / (w + s)) {
                    ma = s / (w + s);
                    ansW = w + s;
                    ansS = s;
                }
            }
        }
    }
    cout << ansW << " " << ansS << endl;
    return 0;
}