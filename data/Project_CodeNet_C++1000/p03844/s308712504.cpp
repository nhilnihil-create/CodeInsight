#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n1, n2;
    char op;
    cin >> n1 >> op >> n2;
    if(op == '+') cout << n1+n2 << endl;
    else cout << n1-n2 << endl;
    return 0;
}