// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <utility>
#include <tuple>
#include <functional>
#include <bitset>
#include <cassert>
#include <complex>
#include <stdio.h>
#include <time.h>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define vv vector< vector< int > >
#define ll long long
#define ALL(a) (a).begin(), (a).end()
const long long mod = 1000000000 + 7;
const long long INF = 9e18;
const double PI = 3.14159265358979323846;

ll gcd(ll a, ll b){if (b == 0) return a;return gcd(b, a % b);}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};


int main(){
    string A, B;
    cin >> A >> B;
    if(A == B) {
        cout << "EQUAL" << endl;
        return 0;
    }
    ll int ans = (int)(A.length()) - (int)B.length();
    if (ans > 0) cout << "GREATER" << endl;
    else if (ans < 0) cout << "LESS" << endl;
    else {
        int num = 0;
        for (int i = 0; i < A.length(); i++) {
            ll int x = stoi(A.substr(num, i+1));
            ll int y = stoi(B.substr(num, i+1));
            if(x == y) {
                num++;
                continue;
            }
            ans = x - y;
            if (ans > 0) {
                cout << "GREATER" << endl;
                return 0;
            }
            else if (ans < 0) {
                cout << "LESS" << endl;
                return 0;
            }
        }
    }
    return 0;
}
