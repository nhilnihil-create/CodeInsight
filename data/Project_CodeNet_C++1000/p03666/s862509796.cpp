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

using namespace std;
typedef pair<llong, llong> ipair;
llong modulo(llong left, llong right) { return (left % right + right) % right; }

llong N, A, B, C, D;
int main(int argc, char **argv) {
    cin >> N >> A >> B >> C >> D;

    bool res = false;
    for(llong i = 0; i < N; ++i) {
        if(-i * D + (N - 1 - i) * C <= B - A &&
            B - A <= -i * C + (N - 1 - i) * D) {
                res = true;
                break;
            }
    }
    
    cout << (res ? "YES" : "NO") << endl;
}