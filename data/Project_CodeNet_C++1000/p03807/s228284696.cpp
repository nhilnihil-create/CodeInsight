#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
int main()
{
    int n;
    cin >> n;
    int odd = 0;
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if(a % 2) odd++;
    }
    if(odd % 2) cout << "NO" << endl;
    else cout << "YES" << endl;
}
