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

int N, a[MAX_N];
int n_uniq_val = -INF, uniq_val = INF, n_uniq_cnt, uniq_cnt;

// n_uniq_val = uniq_val + 1
bool solve() {
    for(int i = 0; i < N; ++i) {
        n_uniq_val = max(n_uniq_val, a[i]);
        uniq_val = min(uniq_val, a[i]);
    }
    if(n_uniq_val - uniq_val >= 2) return false;

    for(int i = 0; i < N; ++i)
        if(a[i] == n_uniq_val) n_uniq_cnt++;
        else uniq_cnt++;
    
    int A = n_uniq_val;
    if(uniq_val == n_uniq_val) {
        if(uniq_val == N - 1) {
            //全てuniq
            A = N;
            return true;
        } else {
            //全てuniqでない
            return N >= 2 * A;
        }
    } else {
        if(A <= uniq_cnt) return false;
        return n_uniq_cnt >= 2 * (A - uniq_cnt);
    }
}

int main(int argc, char **argv) {
    cin >> N;

    for(int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    cout << (solve() ? "Yes" : "No") << endl;
}