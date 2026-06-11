    #include <bits/stdc++.h>
    #define int long long
    const int MOD=1e9+7;
    using pii=std::pair<int,int>;
    using namespace std;
     
    int n, m, x[100005], y[100005];
    int32_t main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cin >> n >> m;
        for(int i = 0; i < n; i++)
            cin >> x[i];
        for(int i = 0; i < m; i++)
            cin >> y[i];
        sort(x, x + n);
        sort(y, y + m);
        int rowsum = 0, colsum = 0;
        for(int i = 0; i < n; i++)
        {
            rowsum += (i - (n - 1 - i)) * x[i];
            rowsum %= MOD;
        }
        for(int i = 0; i < m; i++)
        {
            colsum += (i - (m - 1 - i)) * y[i];
            colsum %= MOD;
        }
        rowsum = (rowsum + MOD) % MOD;
        colsum = (colsum + MOD) % MOD;
        cout << (rowsum * colsum) % MOD << "\n";
        return 0;
    }