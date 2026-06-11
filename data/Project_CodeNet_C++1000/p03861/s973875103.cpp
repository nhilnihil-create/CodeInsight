#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long a, b, x;
    cin >> a >> b >> x;

    long long b_num = b / x;
    long long a_num = (a - 1) >= 0?(a - 1) / x:-1;
    printf("%lld\n", b_num - a_num);

    return 0;
}
