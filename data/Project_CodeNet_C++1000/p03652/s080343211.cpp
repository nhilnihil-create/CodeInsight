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
#define MAX_NM 300

using namespace std;
typedef pair<llong, llong> ipair;
llong modulo(llong left, llong right) { return (left % right + right) % right; }

int N, M;
list<int> sports[MAX_NM];
list<int>::iterator sports_pos[MAX_NM][MAX_NM];

int solve() {
    int res = INF;

    int sports_cnt[MAX_NM];
    for(int t = 0; t < M; ++t) {
        memset(sports_cnt, 0, sizeof(sports_cnt));
        
        for(int i = 0; i < N; ++i)
            sports_cnt[sports[i].front()]++;
        
        int max_val = -INF, max_sports;
        for(int i = 0; i < M; ++i)
            if(max_val < sports_cnt[i]) {
                max_val = sports_cnt[i];
                max_sports = i;
            }
        
        res = min(res, max_val);
        
        for(int i = 0; i < N; ++i)
            sports[i].erase(sports_pos[i][max_sports]);
    }

    return res;
}

int main(int argc, char **argv) {
    cin >> N >> M;

    for(int i = 0; i < N; ++i)
        for(int j = 0; j < M; ++j) {
            int A;
            cin >> A;
            sports[i].push_back(A - 1);
        }
    
    for(int i = 0; i < N; ++i)
        for(auto it = sports[i].begin(); it != sports[i].end(); ++it)
            sports_pos[i][*it] = it;
    
    cout << solve() << endl;
}