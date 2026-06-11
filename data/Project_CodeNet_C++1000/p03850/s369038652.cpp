#define _USE_MATH_DEFINES
#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <complex>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <limits>
#include <climits>
#include <cfloat>
#include <functional>
#include <iterator>
using namespace std;

const long long INF = LLONG_MAX / 2;
const int MAX = 10;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    string op(n-1, ' ');
    for(int i=0; i<n; ++i){
        cin >> a[i];
        if(i < n - 1)
            cin >> op[i];
    }

    vector<vector<long long> > dp(n, vector<long long>(MAX, -INF));
    dp[0][0] = a[0];
    for(int i=1; i<n; ++i){
        for(int j=MAX-1; j>=0; --j){
            long long x = dp[i-1][j];
            if((j % 2 == 0) ^ (op[i-1] == '-'))
                x += a[i];
            else
                x -= a[i];

            dp[i][j] = max(dp[i][j], x);
            if(op[i-1] == '-' && j + 1 < MAX)
                dp[i][j+1] = max(dp[i][j+1], x);
        }
        for(int j=MAX-1; j>0; --j)
            dp[i][j-1] = max(dp[i][j-1], dp[i][j]);
    }
    cout << dp[n-1][0] << endl;

    return 0;
}
