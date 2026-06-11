#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;

const int N = 100010, mod = 1e9 + 7;

int n, a[N];

int qp(int a, int b)
{
    int res = 1;
    while(b)
    {
        if(b & 1) res = (LL)res * a % mod;
        a = (LL)a * a % mod;
        b >>= 1;
    }
    return res;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a[x]++;
    }

    bool flag = true;
    if(a[0] != n % 2) flag = false;
    for(int i = 1 + n % 2; i < n; i += 2)
        if(a[i] != 2)
        {
            flag = false;
            break;
        }


    if(!flag) puts("0");
    else cout << qp(2, n / 2) << endl;
    return 0;
}
