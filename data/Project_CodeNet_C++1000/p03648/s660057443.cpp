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

using namespace std;

typedef long long ll;
typedef pair<int,int> P;

int main() {
    ll K;
    cin >> K;
    
    ll p = K / 50;
    ll q = K % 50;
    
    ll a[50];
    fill(a, a + 50, 49 + p * (51));
    for (int i = 0; i < q; ++i) {
        a[i] += 51;
    }
    for (int i = 0; i < 50; ++i) {
        a[i] -= K;
    }
    
    cout << 50 << endl;
    for (int i = 0; i < 50; i++) {
        printf("%lld ", a[i]);
    }
    
    cout << endl;

    return 0;
}
