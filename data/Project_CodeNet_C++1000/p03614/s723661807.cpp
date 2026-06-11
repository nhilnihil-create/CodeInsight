#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <utility>
#include <algorithm>
#include <functional>
#include <deque>
#define INF 1e9
#define MAX_N 100001

using namespace std;

typedef long long ll;
typedef pair<int,int> P;

int main() {
    int N;
    bool same[MAX_N];
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        int p_i;
        cin >> p_i;
        same[i] = (p_i == i);
    }
    
    int ans = 0;
    for (int i = 1; i <= N; ++i) {
        if (same[i]) {
            ans++;
            same[i + 1] = false;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}
