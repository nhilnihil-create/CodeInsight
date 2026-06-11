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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ma = 0;
    int x = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'I') x++;
        else x--;
        ma = max(ma, x);
    }
    cout << ma << endl;
    return 0;
}