#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int n, m, k;
int main(int argc, char const *argv[])
{
    cin >> n >> m >> k;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i * m + j * n - i * j - i * j == k) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}