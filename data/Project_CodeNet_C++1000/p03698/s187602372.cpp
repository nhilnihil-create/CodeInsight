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
    string S;
    cin >> S;
    set<char> s;
    for(int i = 0; i < S.length(); ++i){
        s.insert(S[i]);
    }
    if(s.size() == S.length()) cout << "yes" << endl;
    else cout << "no" << endl;

    return 0;
}