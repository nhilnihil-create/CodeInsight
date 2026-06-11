#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cassert>
#include <map>
#include <numeric>
#include <cstring>
#include <set>
#include <ctime>
#include <queue>

using namespace std;

int main () {
    //ifstream cin("input.in");
    int a, b, c;
    cin >> a >> b >> c;
    if (a % 2 == 0  && a == b && a == c) {
        cout << "-1\n";
        return 0;
    }
    int answer = 0;
    while (a % 2 == 0 && b % 2 == 0 && c % 2 == 0) {
        int a0 = (b + c) / 2, b0 = (a + c) / 2, c0 = (a + b) / 2;
        a = a0;
        b = b0;
        c = c0;
        answer++;
    }
    cout << answer << "\n";
    return 0;
}



