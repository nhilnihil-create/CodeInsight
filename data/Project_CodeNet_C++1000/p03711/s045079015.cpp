#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;

int groupNum(int num){
    if(num == 1 || num == 3 || num == 5 || num == 7 || num == 8 || num == 10 || num == 12) {
        return 1;
    } else if(num == 4 || num == 6 || num == 9 || num == 11) {
        return 2;
    } else if(num == 2) {
        return 3;
    } else {
        return -1;
    }
}

int main() {
    int x, y;
    cin >> x >> y;

    int xGroup = groupNum(x);
    int yGroup = groupNum(y);

    if(xGroup == yGroup) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}