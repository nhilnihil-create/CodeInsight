#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    int num;
    int sum=0;

    cin >> num;

    for (int i = 0; i < num; i++) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        sum += tmp2 - tmp1 + 1;
    }

    cout << sum << endl;
}
