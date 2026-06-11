#define loop(i,j,k) for(long long i = j;i < k;i++)

#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstdint>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

int main(void) {
    int64_t n;
    cin >> n;
    int64_t a[300][300],b[300][300];
    loop(i,0,n)loop(j,0,n)b[i][j] = 0;
    loop(i,0,n)loop(j,0,n)cin>>a[i][j];
    loop(k,0,n)loop(i,0,n)loop(j,0,n){if(a[i][j] > a[i][k] + a[k][j]) {
        cout << -1;
        return 0;
    } else if (a[i][j] == a[i][k] + a[k][j] && i != k && j != k) {
        b[i][j] = INT32_MAX / 2;
    }}
    int64_t res = 0;
    loop(i,0,n)loop(j,0,n)if(b[i][j] != INT32_MAX / 2)res += a[i][j];
    cout << res / 2;
}
