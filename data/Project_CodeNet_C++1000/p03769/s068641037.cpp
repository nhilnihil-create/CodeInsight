#include <bits/stdc++.h>

using namespace std;

int a[500], nr = 0;
long long n;

void get_ans(long long k, int id1, int id2)
{
    if(k==1)
    {
        int i;
        cout << 2*nr << '\n';
        for(i=1; i<id1; ++i) cout << a[i] << ' ';
        for(i=id2+1; i<=100; ++i) cout << a[i] << ' ';

        for(i=nr; i; --i) cout << i << ' ';
        cout << '\n';
        return;
    }

    if(k&1LL)
    {
        a[id1] = ++nr;
        get_ans(k-1, id1+1, id2);
    }
    else
    {
        a[id2] = ++nr;
        get_ans(k/2, id1, id2-1);
    }
}

int main()
{
    cin >> n; nr = 0;
    get_ans(n+1, 1, 100);

    return 0;
}
