#include<bits/stdc++.h>

using namespace std;
#define taskname "A"
#define pb  push_back
#define mp  make_pair
#ifndef LOCAL
#define cerr if(0)cout
#endif

typedef long double ld;
typedef long long ll;
typedef pair<int,int> ii;
const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;
int n, a[maxn];
int l[maxn] , r[maxn];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen(taskname".INP","r")){
        freopen(taskname".INP", "r",stdin);
        freopen(taskname".OUT", "w",stdout);
    }
    cin >> n;
    for(int i = 1 ; i <= n ; ++i)cin >> a[i];
    vector<int> s;
    for(int i = 1 ; i <= n ; ++i){
        while(s.size() && a[s.back()] >= a[i])s.pop_back();
        if(s.size())l[i] = s.back();
        else l[i] = 0;
        s.pb(i);
    }
    s.clear();
    for(int i = n ; i >= 1 ; --i){
        while(s.size() && a[s.back()] >= a[i])s.pop_back();
        if(s.size())r[i] = s.back();
        else r[i] = n + 1;
        s.pb(i);
    }
    ll res = 0;
    for(int i = 1 ; i <= n ; ++i){
//        cout << l[i] << " " << r[i] << endl;
        res += 1ll * (i - l[i]) * (r[i] - i) * a[i];
    }
    cout << res;
}
