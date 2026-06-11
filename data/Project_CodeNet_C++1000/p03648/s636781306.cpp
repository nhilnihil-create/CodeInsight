#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define imfor(i, n) for(int i = 0; i < n; i++)
using namespace std;
 
int main() {
    long long k;
    cin >> k;
    cout << 50 << endl;
    imfor(i, 50) {
        cout << i + (i + k) / 50 << " ";
    }
    cout << endl;
    return 0;
}