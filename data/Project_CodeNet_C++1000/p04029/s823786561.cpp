#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,no-stack-protector,fast-math")
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define IO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
const int N = 1e2 + 5, M = 2 * N + 5;

int main(){
    int n;
    scanf("%d", &n);
    printf("%d\n", n * (n + 1) / 2);
}