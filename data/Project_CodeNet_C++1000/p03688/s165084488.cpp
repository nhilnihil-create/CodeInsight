#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int l = a[0];
    int h = a[n-1];
    int num = h-l;
    if(num > 1)
    {
        cout << "No" << endl;
    }
    else if(num == 1)
    {
        int lc = 0;
        for(int i = 0; i < n; i++)
        {
            if(a[i] == l) lc++;
        }
        int hc = n - lc;
        if(l < lc || l > lc - 1 + hc / 2 || h > hc/2 + l || h < lc)
        {
            cout << "No" << endl;
        }
        else cout << "Yes" << endl;
    }
    else
    {
        int cand = n / 2;
        if(l <= cand || l == n-1)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}
