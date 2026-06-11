#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
int main()
{
    int n, l;
    cin >> n >> l;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int pos = 0;
    for(int i = 0; i < n-1; i++)
    {
        if(a[i] + a[i+1] >= l) pos = i+1;
    }
    if(pos == 0)
    {
        cout << "Impossible" << endl;
    }
    else
    {
        cout << "Possible" << endl;
        for(int i = 1; i < pos; i++) cout << i << endl;
        for(int i = n-1; i >= pos; i--) cout << i << endl;
    }
}
