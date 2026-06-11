#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long int lli;

int main() {
    int N;
    cin >> N;
    int beki = (int)log2(N);
    int temp = (int)pow(2, beki);
    cout << temp << endl;
    return 0;
}
