#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef pair<int, int> pair;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> x(n);
    rep(i, n) {
        cin >> x[i];
    }   

    int ans = 0;

    rep(i, n) {
        if (x[i] <= k - x[i]) {
            ans += x[i] * 2;
            continue;
        }
        else {
            ans += (k - x[i]) * 2;
        }
    }

    cout << ans << endl;
    
    return 0;
}
