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
    int H, W;
    cin >> H >> W;
    string s[H+2];
    for(int i = 0; i < H+2; i++){
        s[i] = "";
        for(int j = 0; j < W+2; j++){
            s[i] += "#";
        }
    }
    string a;
    for(int i = 1; i <= H; ++i){
        cin >> a;
        s[i].replace(1, W, a);
    }

    for(int i = 0; i < H+2; ++i){
        cout << s[i] << endl;
    }
    return 0;
}
