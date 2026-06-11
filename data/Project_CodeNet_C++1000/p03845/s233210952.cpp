#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, p, x;
    cin >> n;
    int t[n+2] = {};
    for(int i = 1; i <= n; i++) cin >> t[i];
    cin >> m;
    while(m--)
    {
        int sum = 0;
        cin >> p >> x;
        for(int i = 1; i <= n; i++){
            if(i == p) sum += x;
            else sum += t[i];
        }
        cout << sum << endl;
    }
}