#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = 1; i <= n; i++)
using P = pair <int, int>;


int main() {
    int a,b;
    char op;
    cin >> a>> op >>b;

    if(op=='+') cout << a+b <<endl;
    else cout << a-b <<endl;
}