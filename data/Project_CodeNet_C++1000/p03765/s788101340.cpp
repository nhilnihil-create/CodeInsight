#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#define int         int64_t
#define ii          pair<int,int>
#define dd          pair<double,double>
#define vi          vector<int>
#define pb          push_back
#define all(x)      (x).begin(), (x).end()
#define checkBit(v, p)      (v&(1LL << p))
#define loop(i,a,b) for(int i = a;i < int(b);i++)
#define x           first
#define y           second
using namespace std;
int inf = 2e9, mod = 1e9 + 7;

int32_t main()
{
    ios_base::sync_with_stdio(false); cout << fixed <<setprecision(0);
    string s, t; cin >> s >> t;
    vi pres(s.size()+1), pret(t.size()+1);
    pres[0] = pret[0] = 0;
    for(int i=0;i<s.size();i++) pres[i+1] = (pres[i] + (1 + s[i] - 'A')) % 3;
    for(int i=0;i<t.size();i++) pret[i+1] = (pret[i] + (1 + t[i] - 'A')) % 3;
    int q; cin >> q;
    for(int a ,b,c,d;q--;){
        cin >> a >> b >> c >> d;
        if((pres[b] - pres[a - 1] + 3) % 3 == (pret[d] - pret[c - 1] + 3) % 3) cout <<"YES";
        else cout <<"NO";
        cout <<'\n';
    }
    cout << endl;
    return 0;
}
