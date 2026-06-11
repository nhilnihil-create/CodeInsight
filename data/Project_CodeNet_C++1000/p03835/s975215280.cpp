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
    int k, s; 
    cin >> k >> s;
    int ans = 0;
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j <= k; j++) {
            int l = s - i - j; 
            if (l <= k && l >= 0) {
                ans++;
            }
        }
    }
    cout << ans << endl;
}
