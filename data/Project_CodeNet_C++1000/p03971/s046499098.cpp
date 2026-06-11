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
const int inf = 1000000000;

int main(){
    int n, a, b;
    string s;
    cin >> n >> a >> b >> s;
    int cou = 0, kco = 0;
    rep (i, n) {
        if (s[i] == 'c') {
            cout << "No" << endl;
            continue;
        }

        else if (s[i] == 'a'){
            if (cou < a + b) {
                cout << "Yes" << endl;
                cou++;
                continue;
            }
            else {
                cout << "No" << endl;
                continue;
            }
        }

        else {
            if (cou < a + b && kco < b) {
                cout << "Yes" << endl;
                cou++;
                kco++;
                continue;
            }
            else {
                cout << "No" << endl;
                continue;
            }
        }
    }

    return 0;
} 