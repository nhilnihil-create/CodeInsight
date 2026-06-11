#include <bits/stdc++.h>

#define ll              long long
#define LMx             LLONG_MAX
#define LMn             LLONG_MIN
#define PI              3.14159265
#define endl            '\n'
#define cd              cout << '\n';
#define ys              cout << "YES"; return;
#define no              cout << "NO"; return;
#define pii             pair<int,int>
#define IOS             ios::sync_with_stdio(0);
#define vi              vector<int>
#define vll             vector<long long>
#define vpii            vector<pair<int,int>>
#define vpll            vector<pair<long long, long long>>
#define pb              push_back
#define in              insert
#define mp              make_pair
#define all(a)          a.begin(),a.end()
#define rall(a)         a.rbegin(),a.rend()
#define fr              first
#define sc              second
#define sz(a)           a.size()
#define min3(a,b,c)     min(a,min(b,c))
#define max3(a,b,c)     max(a,max(b,c))
#define min4(a,b,c,d)   min(a,min(b,min(c,d)))
#define max4(a,b,c,d)   max(a,max(b,max(c,d)))
#define MEM(a,x)        memset(a,x,sizeof(a))
#define SORT(v)         sort(v.begin(),v.end())
#define REV(v)          reverse(v.begin(),v.end())
#define buga(i,n,a)     for(i = 0; i < n; ++i) cout << a[i] << " ";
#define bugv(i,n,v)     cout << endl; for(i = 0; i < n; ++i) cout << v[i].first << " " << v[i].second << endl; cout << endl;

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

using namespace std;

/*ll myceil(ll a, ll b)
{
	return ((a+b-1)/b);
}

ll myfloor(ll a, ll b)
{
	return a/b;
}*/


void solve()
{
	ll c, d, i, j, k, l, m, n, x, y, z, r, sum = 0, ans = 0, tmp, cnt = 0;
	//string s, t;
	ll a, b;
	char ch;
	cin >> a >> ch >> b;
	if(ch == '+')
		cout << a+b;
	else
		cout << a-b;
}


int main()
{
    IOS;
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
        cout << endl;
    }
    return 0;
}