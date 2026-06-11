#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <array>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define loop(i, a, n) for (int i = a; i < (n); i++)
#define all(in) in.begin(), in.end()
const int INF = 1e9;
const int MOD = 1e9 + 7;
int main() {
    string S;
    cin >> S;
    if (S.size() < 4 || S.substr(0, 4) != "YAKI") {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
    //cout << S.substr(0, 3) << endl;
    return 0;
}