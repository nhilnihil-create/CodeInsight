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
#define MAX_N 301

using namespace std;

typedef long long ll;
typedef pair<int,int> P;

int N;
ll A[MAX_N][MAX_N];

ll check() {
    ll res = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            bool flag = false;
            for (int k = 0; k < N; ++k) {
                if (i == j || j == k || k == i) continue;
                if (A[i][j] > A[i][k] + A[k][j]) {
                    return -1;
                } else if (A[i][j] == A[i][k] + A[k][j]) {
                    flag = true;
                }
            }
            if (flag) {
                res += A[i][j];
            }
        }
    }
    return res;
}


int main() {
    cin >> N;
    ll sum = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> A[i][j];
            sum += A[i][j];
        }
    }
    
    ll res = check();
    if (res == -1) {
        cout << -1 << endl;
    } else {
        cout << (sum - res) / 2 << endl;
    }
    
    return 0;
}
