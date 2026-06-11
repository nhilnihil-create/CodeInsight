#include<bits/stdc++.h>
using namespace std;

#define FOR(a, b, c) for(int a = b; a <= c; ++a)
#define FORW(a, b, c) for(int a = b; a >= c; --a)
#define int long long

int n, len, powe[20];
string ans;

bool check(int x)   {
    cout << "? " << x << '\n'; cout.flush();
    string tmp; cin >> tmp;
    return (tmp == "Y");
}

int solve_1()   {

    int l = 0, r = 9;
    while(l < r)    {
        int mid = (l + r) / 2;
        if(check(3 * powe[mid])) r = mid;
        else l = mid + 1;
    }
    return l;
}

int solve_2()   {

    int l = 0, r = 9;
    while(r > l)    {
        int mid = (l + r + 1) / 2;
        if(check(powe[mid])) l = mid;
        else r = mid - 1;
    }
    return l;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    powe[0] = 1;
    FOR(i, 1, 9) powe[i] = powe[i - 1] * 10;

    bool flag = check(1000000000);
    if(flag) len = solve_1();
    else len = solve_2();

    int l = powe[len], r = powe[len + 1] - 1;
    while(r > l)    {
        int mid = (l + r) / 2;
        if(check(mid * 10)) r = mid;
        else l = mid + 1;
    }
    cout << "! " << l << '\n'; cout.flush();
}
