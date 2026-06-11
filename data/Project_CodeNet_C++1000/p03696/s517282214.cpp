#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    int open = 0;
    int close = 0;

    for (int i = 0; i < N; i++) {
        if (S[i] == '(') {
            open++;
        } else {
            if (open > 0) {
                open--;
            } else {
                close++;
            }
        }
    }
    for (int i = 0; i < close; i++) {
        cout << "(";
    }
    cout << S;
    for (int i = 0; i < open; i++) {
        cout << ")";
    }
    cout << endl;

    return 0;
}
