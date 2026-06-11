#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>

#define DIV 998244353

using namespace std;
using ll = long long;
using ldb = long double;

int main() {
    ll N, A, B; cin >> N >> A >> B;
    ll ans = (N - 2) * (B - A) + 1;
    cout << max((ll)0,ans) << endl;
}
