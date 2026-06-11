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
    int a, b, c;
    cin >> a >> b >> c;
    if (a == b && b == c && a % 2 == 0) {
        cout << "-1" << endl;
        return 0;
    }

    if (a == b && b == c && a % 2 == 1) {
        cout << 0 << endl;
        return 0;
    }

    int ans = 0;
    bool w = true;

    while (w) {
        if (a % 2 || b % 2 || c % 2) {
            w = false;
            cout << 0 << endl;
            return 0;
        }
        int aa = a, bb = b, cc = c;
        ans++;
        a = (bb + cc) / 2;
        b = (aa + cc) / 2;
        c = (aa + bb) / 2;
        if (a % 2 || b % 2 || c % 2) w = false;
    }    

    cout << ans << endl;
    
    return 0;
}