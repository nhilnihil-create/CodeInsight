    #include <bits/stdc++.h>
    #include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/tree_policy.hpp>
     
    using namespace __gnu_pbds;
    using namespace std;
     
    #define ff first
    #define ss second
    #define pb push_back
    #define pf push_front
    #define mp make_pair
    #define popb pop_back
    #define popf pop_front
    #define all(v) v.begin(), v.end()
    #define fori(i, j, k) for (int i = (j); i < (int)(k); i++)
    #define forb(i, j, k) for (int i = (j); i >= (int)k; i--)
    #define lchild(ind) 2 * ind + 1
    #define rchild(ind) 2 * ind + 2
    #define bug(val) cout << "# " << val << endl;
    #define bugs(val) cout << '_' << val;
    #define bugl(val) cout << "## " << val << endl;
     
    template<typename T>
    using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
     
    typedef long long ll;
    typedef long double ld;
    typedef pair<int, int> pii;
    typedef pair<int, ll> pil;
    typedef pair<ll, int> pli;
    typedef pair<ll, ll> pll;
    typedef pair<int, pll> pip;
    typedef pair<ll, pll> plp;
    typedef pair<pll, int> ppi;
    typedef pair<pll, ll> ppl;
    typedef pair<pll, pll> ppp;
    typedef vector<int> vi;
    typedef vector<ll> vll;
     
    const int maxn = 1e5 + 1;
    const ll inf = 2e18, mod = 1e9 + 7;
     
    int n, a[maxn];
     
    bool solve()
    {
    	int o = 0;
    	fori (i, 0, n)
    		if (a[i] & 1)
    			o++;
    	int e = n - o;
    	if (e & 1)
    		return true;
    	else
    	{
    		if (o == 1)
    		{
    			int val = -1;
    			fori (i, 0, n)
    				if (a[i] & 1)
    					val = a[i];
    			if (val == 1)
    				return false;
    			val--;
    			fori (i, 0, n)
    				if (!(a[i] & 1))
    					val = __gcd(val, a[i]);
    			fori (i, 0, n)
    				a[i] /= val;
    			return !solve();
    		}
    		else if (o > 1)
    			return false;
    	}
    	return false;
    }
     
    int main()
    {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
     
    	cin >> n;
    	fori (i, 0, n)
    		cin >> a[i];
    	bool ans = solve();
    	cout << (ans ? "First" : "Second") << endl;
    }
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     