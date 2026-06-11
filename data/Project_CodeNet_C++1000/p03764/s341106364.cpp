#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back

#define int int64_t

const int MOD = 1e9+7;
 
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    int x[n];
    int y[m];
    for(int i=0;i<n;i++)
        cin>>x[i];
    for(int j=0;j<m;j++)
        cin>>y[j];

    int rows=0,cols=0;
    for(int i=0;i<n;i++) {
        rows+=(i-(n-i-1))*x[i];
        rows%=MOD;
    }
    for(int i=0;i<m;i++) {
        cols+=(i-(m-i-1))*y[i];
        cols%=MOD;
    }
    //rows=(rows+MOD)%MOD;
    //cols=(cols+MOD)%MOD;
    cout<<(cols*rows)%MOD;

    return 0;
}