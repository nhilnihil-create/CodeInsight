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



int main() {
    string s;
    cin >> s;
    int p1, p2;
    for (int i = 0; i < s.length(); i++) {
        if (s.at(i) == 'A') {
            p1 = i;
            break;
        }
    }
    for (int i = s.length() - 1; i >= 0; i--) {
        if (s.at(i) == 'Z') {
            p2 = i;
            break;
        }
    }
    int ans = p2 - p1 + 1;
    cout << ans << endl;
    return 0;
}