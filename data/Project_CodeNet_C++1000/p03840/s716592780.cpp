#include <iostream>
using namespace std;

int main() {
    int64_t ai, ao, at, aj, al, as, az;
    cin >> ai >> ao >> at >> aj >> al >> as >> az;
    int64_t answer = ai / 2 * 2 + ao + aj / 2 * 2 + al / 2 * 2;
    if (ai & aj & al & 1) {
        answer += 3;
    } else if ((ai & 1) + (aj & 1) + (al & 1) == 2 && ai && aj && al) {
        answer += 1;
    }
    cout << answer << endl;
    return 0;
}
