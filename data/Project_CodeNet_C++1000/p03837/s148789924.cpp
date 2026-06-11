#include<bits/stdc++.h>


int main(void) {
    using namespace std;

    long n, m;
    cin >> n >> m;

    vector<vector<long>> d(n, vector<long>(n, 1e9));

    vector<tuple<long,long,long>> abc(m);
    for(int i=0; i<m; i++) {
        long a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        d[a][b] = d[b][a] = min(d[a][b], c);
        abc[i] = make_tuple(a, b, c);
    }

    for(int k=0; k<n; k++)
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

    long r = 0;
    for(auto &x: abc) {
        long a, b, c;
        tie(a, b, c) = x;
        if(d[a][b] < c) r++;
    }
    cout << r << endl;
}
