#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    long long num, c, k;
    long long cntBus = 0;

    cin >> num >> c >> k;

    vector<long long> vec(num);
    for (int i = 0; i < num; i++) { cin >> vec.at(i); }

    sort(vec.begin(), vec.end());

    long long cnt = 0, genkaiTi;
    for (int i = 0; i < num;) {
        cntBus++;
        cnt = 0;
        genkaiTi = vec.at(i) + k;

        while (i < num && vec.at(i) <= genkaiTi && cnt < c) {
            i++;
            cnt++;
        }
    }

    cout << cntBus;
}