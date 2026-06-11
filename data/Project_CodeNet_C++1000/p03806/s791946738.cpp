#define _USE_MATH_DEFINES
#include  <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include<math.h>
#include<iomanip>
#include<stdio.h>
#include <stdlib.h>
#include<stdio.h>
#include <queue>
#include<map>
#include <sstream>
#include<set>
#include<stack>
typedef long long int ll;
//#include<bits/stdc++.h>


using namespace std;




    ll dp[51][510][510];
int main()
{
    
    int n, m, p;
    cin >> n >> m >> p;
    vector<int>a(n), b(n),c(n);

    for (int i = 0; i < n; i++)cin >> a[i] >> b[i] >> c[i];


    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 510; j++) {
            for (int k = 0; k < 510; k++) {
                dp[i][j][k] = 99999999999999999;
            }
        }
    }

    dp[0][0][0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 500; j++) {
            for (int k = 0; k < 500; k++) {
                if (dp[i][j][k] == 1000000000)continue;
                dp[i + 1][j][k] = min(dp[i][j][k], dp[i + 1][j][k]);
                dp[i + 1][j + a[i]][k + b[i]] = min(dp[i + 1][j + a[i]][k + b[i]], dp[i][j][k] + c[i]);
            }
        }
    }
    ll ans = 99999999999999999;
    for (int i = 1; i < 500; i++) {
        for (int j = 1; j < 500; j++) {
            if (m * j != i * p)continue;
            ans = min(ans, dp[n][i][j]);
        }
    }
    if (ans == 99999999999999999)cout << -1 << endl;
    else cout << ans << endl;

    return 0;

}