#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int,int> PP;

/*
    freopen("input","r",stdin);
    freopen("output","w",stdout);
*/

int gcd(int a, int b) {
    if (a < b) swap(a, b);
    if (a % b == 0) return b;
    return gcd(b, a % b);
}

bool win(vector<int> X) {
    int sum = 0;
    int n = X.size();
    int od = 0;
    int one = 0;
    for (int i = 0;i < n;i++) {
        if (X[i] % 2) od++;
        if (X[i] == 1) one++;
        sum += (X[i] - 1);
        sum %= 2;
    }
    // win directly.
    if (sum) return 1;
    if (one) return 0;
    if (od == 1) {
        // I tried!
        int g = (X[0] / 2) * 2;
        for (int i = 1;i < n;i++) g = gcd(g, (X[i] / 2) * 2);
        for (int i = 0;i < n;i++) X[i] /= g;
        return !win(X);
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> X(n);
    for (int i = 0;i < n;i++) cin >> X[i];
    if (win(X)) cout << "First" << endl;
    else cout << "Second" << endl;
    return 0;
}