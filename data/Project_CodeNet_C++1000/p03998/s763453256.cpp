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
    string a, b, c;
    cin >> a >> b >> c;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    reverse(c.begin(), c.end());

    char p = a.back();
    a.pop_back();

    while (true) {
        switch (p) {
        case 'a':
            if (a.empty()) {
                cout << "A" << endl;
                return 0;
            }
            p = a.back();
            a.pop_back();
            break;
        case 'b':
            if (b.empty()) {
                cout << "B" << endl;
                return 0;
            }
            p = b.back();
            b.pop_back();
            break;
        case 'c':
            if (c.empty()) {
                cout << "C" << endl;
                return 0;
            }
            p = c.back();
            c.pop_back();
            break;
        }
    }

    return 0;
}