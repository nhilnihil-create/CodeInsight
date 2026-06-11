#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int calcDivisionNum(int num) {
    int dn = 0;
    while (num) {
        if (num % 2 == 0) {
            ++dn;
            num /= 2;
        } else {
            break;
        }
    }
    return dn;
}

int main() {
    int N;
    cin >> N;

    int dn = -1;
    int index = 0;
    for (int i = 1; i <= N; ++i) {
        if (dn < calcDivisionNum(i)) {
            dn = calcDivisionNum(i);
            index = i;
        }
    }
    cout << index << endl;

}
