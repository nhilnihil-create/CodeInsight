#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <bitset>
#include<iomanip>//小数点以下を精度良く表示
#include <map>
#include<set>

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <numeric>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define INF 2000000000
#define INF2 1000000000000000000
#define PI 3.1415926535
#define rep(i,n) for(int i=0;i<(n);i++)
typedef pair<int, int> P;
const ll MOD = 1000000007;
using Graph = vector<vector<int>>;

#define MAX_N 50005//ここにNの最大値を入れる
#define MAX_K 100005


double max(double a, double b) {
    if (a > b) return a;
    return b;
}

int main() {
    int k, s;
    cin >> k >> s;
    int ans = 0;
    for (int x = 0; x <= k; x++) {
        for (int y = 0; y <= k; y++) {
            int z = s - x - y;
            if (z >= 0 && z <= k) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}