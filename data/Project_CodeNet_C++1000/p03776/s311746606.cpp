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

//#include<bits/stdc++.h>


using namespace std;


int main()
{
    
    int n;
    cin >> n;
    long long int a, b;
    cin >> a >> b;

    vector<long long int>p(n);
    map<long long int, int>f;

    for (int i = 0; i < n; i++) {
        cin >> p[i];
        f[p[i]]++;
    }
    double ans = 0;
    long long int d = 0,s=0;
    int g = 0;
    sort(p.rbegin(), p.rend());
    for (int i = 0; i < a; i++) {
        g++;
        ans += p[i];
     //   d *= f[p[i]];
        f[p[i]]--;
    }
    g = 0;
    cout << setprecision(20);
    cout << ans / a << endl;
    for (int i = 0; i < n; i++) {
        if (p[i] == p[a - 1]) {
            d++;
            if (i < a)g++;
        }
    }

    int v = b;
    
    long long int N[55][55] = {};
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || i == j)N[i][j] = 1;
            else {
                N[i][j] = N[i-1][j-1] + N[i - 1][j];
            }
        }
    }
    if (p[0] == p[a - 1]) {
        for (int i = a; i <= min(b,d); i++) {
            s += N[d][i];
        }
    }
    else {
        s += N[d][g];
    }


    cout << s << endl;

    return 0;

}