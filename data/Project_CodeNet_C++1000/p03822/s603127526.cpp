#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#define llong long long
#define INF (__INT32_MAX__ / 2)
#define EPS 10e-8
#define MAX_N 100000

using namespace std;
typedef pair<llong, llong> ipair;
llong modulo(llong left, llong right) { return (left % right + right) % right; }

int N;
vector<int> losers[MAX_N];

int solve(int player) {
    vector<int> children;
    for(int i = 0; i < losers[player].size(); ++i)
        children.push_back(solve(losers[player][i]));
    
    sort(children.begin(), children.end());

    int depth = 0;
    for(int i = 1; i <= children.size(); ++i) {
        depth = max(depth, i + children[children.size() - i]);
    }

    return depth;
}

int main(int argc, char **argv) {
    cin >> N;
    for(int i = 1; i < N; ++i) {
        int a;
        cin >> a;
        losers[a - 1].push_back(i);
    }
    
    cout << solve(0) << endl;
}