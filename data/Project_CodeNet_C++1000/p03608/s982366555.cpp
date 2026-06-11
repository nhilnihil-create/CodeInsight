    #include <iostream>
    #include <queue>
    #include <utility>
    #include <set>
    #include <algorithm>
    using namespace std;
    long long n, m, r, t1, t2, t3, d[205][205], b[205 * 205];
     
    int main()
    {
        cin >> n >> m >> r;
        for (int i = 0; i < r; ++i)
            cin >> b[i];
      
      
      	for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= n; ++j)
                  	if(i != j)
                		d[i][j] = 1e9;
      
        for (int i = 0; i < m; ++i)
        {
            cin >> t1 >> t2 >> t3;
            d[t1][t2] = t3;
            d[t2][t1] = t3;
        }
     
      
        for (int k = 1; k <= n; ++k)
            for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= n; ++j)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
     
        long long mn = 1 << 30;
        sort(b, b + r);
        do
        {
            long long rj = 0, t = b[0];
            for (int i = 1; i < r; ++i)
                rj += d[t][b[i]], t = b[i];
            mn = min(mn, rj);
        } while (next_permutation(b, b + r));
        cout << mn << endl;
    }