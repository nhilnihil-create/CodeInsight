#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 110;

using namespace std;

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int n;
        cin >> n;
        vector < int > a(n);
        long long inf = 1e18;
        vector < long long > d(n + 1, - inf);
        vector < long long > f(n + 1, - inf);
        
        d[0] = 0;
        
        for(int i = 0; i < n; i++){
                cin >> a[i];

                d[i + 1] = max(d[i + 1], d[i] + a[i] / 2);
                d[i + 1] = max(d[i + 1], f[i] + a[i] / 2);
                if(a[i] > 0)f[i + 1] = max(f[i + 1], d[i] + (a[i] - 1) / 2);
                if(a[i] > 0)d[i + 1] = max(d[i + 1], f[i] + (a[i] - 1) / 2 + 1);
                if(a[i] > 0)f[i + 1] = max(f[i + 1], f[i] + (a[i] - 1) / 2);
                if(a[i] > 1)f[i + 1] = max(f[i + 1], f[i] + (a[i] - 2) / 2 + 1);
                d[i] = max(d[i], f[i]);
        }

        cout << max(f.back(), d.back()) << "\n";
}
