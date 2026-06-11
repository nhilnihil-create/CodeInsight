#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef vector<int> vi ;
typedef pair<int,int> ii ;
typedef pair<ii,int> ill;
typedef tuple<int,int,int> tt;
const int maxN = 1e5+7;
const int INF = 1e18;

int ps[maxN] , pt[maxN];
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s , t;
    int q;
    cin >> s >> t;
    pt[0] = ps[0] = 0;
    for(int i = 0 ; i< s.size() ; i++)
      ps[i+1] = ps[i] + ((s[i]=='A') ? 1 : -1);
    for(int i = 0 ; i< t.size() ; i++)
      pt[i+1] = pt[i] + ((t[i]=='A') ? 1 : -1);
    cin >> q;
    while(q--)
    {
        int u , v , l , r;
        cin >> l >> r >> u >> v;
        int cur_s =ps[r] - ps[l-1] ;
        int cur_t = pt[v] -pt[u-1] ;
        if ( cur_s % 3 == -2 ) cur_s = 1;
        if ( cur_s % 3 == -1) cur_s = 2;
        if ( cur_t % 3 == -2 ) cur_t = 1;
        if ( cur_t % 3 == -1) cur_t = 2;
        if ( cur_s %3 == cur_t % 3 )
            cout<<"YES";
        else cout<<"NO";
        cout<<"\n";
    }

    return 0;
}
