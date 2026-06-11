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
    string X;
    cin >> X;

    int output = 0;
    int t = 0;
    int s = 0;
    for (int i = 0; i < X.size(); i++) {
        if (X[i] == 'S') s++;
        if (X[i] == 'T') {
            if (s == 0)
                output++;
            else
                s--;
        }
    }

    cout << output + s << endl;

    return 0;
}
