#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;

    int k = 1;
    int sum = 0;
    while(sum < n) {
        sum += k;
        k++;
    }

    for(int i = 1; i < k; i++) {
        if(i == sum-n) {
            continue;
        }
        cout << i << "\n";
    }

    return 0;
}