#include <bits/stdc++.h>
using namespace std;
int main( ) {
    //freopen("A.01.inp","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b;
    char op;
    cin >> a >> op >> b;
    int g = a-b;
    int ret = a+b;
    if (op=='-') ret = a-b;
    cout << ret << endl;
    return 0;
}