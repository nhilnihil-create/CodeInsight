#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

typedef long long int lli;
typedef pair<lli, lli> ii;

using namespace __gnu_pbds;
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int N = 2e5 + 5;
int n, k;
lli a[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

   // freopen("input.txt","r",stdin);

    while(cin >> n >> k)
    {


        for(int i = 0; i < n; i++)
            cin >> a[i];

        //0 normalization
        for(int i = 0; i < n; i++)
            a[i] -= k;
        k = 0;

        ordered_set t;

        lli thres = 0;

        lli ans = 0;
        for(int i = 0 ; i < n; i++)
        {
            //Modify thres and insert new element aptly translated
            t.insert({thres, i});
            thres -= a[i];
            ans += (i + 1 - t.order_of_key({thres, (lli)-1}));


        }
        cout << ans << endl;
    }
    return 0;
}
