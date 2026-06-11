#include<bits/stdc++.h>

using namespace std;

#define ll  long long
#define ld  double

#define all(x)  x.begin(),x.end()
#define sz(x)   (int)x.size()

#define pb  emplace_back
#define X   first
#define Y   second

const int   N   = 3e5 + 5;

typedef pair<int,int>   ii;

vector<int> add[N];
vector<int> rem[N];

vector<int> dvs[N];

int t[N];

int upd(int p,int v)    {
    for(; p < N ; p += p & -p)
        t[p] += v;
}
int get(int p)  {
    int ans = 0;
    for(; p > 0 ; p -= p & -p)
        ans += t[p];
    return  ans;
}

int ans[N];

int main()  {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    for(int i = 1 ; i < N ; ++i)
    for(int j = i ; j < N ; j += i)
        dvs[j].pb(i);

    int m;  cin >> m;
    int n;  cin >> n;

    for(int i = 0 ; i < m ; ++i)    {
        int l;  cin >> l;
        int r;  cin >> r;

        add[l].pb(l);
        rem[r].pb(l);
    }

    for(int i = 1 ; i <= n ; ++i)   {
        for(int x : add[i]) upd(x,1);
        for(int x : dvs[i])
            ans[x] += get(i),
            ans[x] -= get(i - x);

        for(int x : rem[i]) upd(x,-1);
    }
    for(int i = 1 ; i <= n ; ++i)
        cout << ans[i] << "\n";
}