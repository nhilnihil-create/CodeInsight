#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
#define ll long long
#define ld long double
#define f first
#define s second
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

const int N = 2e5+5;
ll n , m , a[N] , nn , ans[105][105];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    cin >> nn;
    for(int i=1; i<=nn; i++)
        cin >> a[i];

    int k = 1;
    for(int i=1; i<=n; i++)
    {
        if (i%2)
        {
            for(int j=1; j<=m; j++)
            {
                if (a[k]==0) k++;
                ans[i][j] = k;
                a[k]--;
            }
        }
        else
        {
            for(int j=m; j>=1; j--)
            {
                if (a[k]==0) k++;
                ans[i][j] = k;
                a[k]--;
            }
        }
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1;j<=m; j++)
            cout << ans[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}