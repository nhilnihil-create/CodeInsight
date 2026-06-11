//#pragma comment(linker, "/stack:200000000")
//#pragma GCC target ("avx2")
//#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

#define fastio                              ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
#define read                                freopen("input.txt", "r", stdin);
#define write                               freopen("output.txt", "w", stdout);
#define nl                                  '\n'
#define LCM(a,b)                            (a / __gcd(a,b) ) *b
#define GCD(a,b)                            __gcd(a,b)
#define mem(v, val)                         memset(v, val, sizeof(v))
#define TC                                  int t; cin >> t; for(int tc = 1; tc <= t; tc++)
#define inp(x)                              for(auto& iinput:x) cin >> iinput
#define out(x)                              for(auto& ooutput:x) cout << ooutput << ' '; cout << nl;
#define sq(a)                               ((a) * (a))

#define ll                                  long long
#define vi                                  vector<int>
#define pb                                  push_back
#define vpii                                vector<pair<int, int>>
#define mp                                  make_pair
#define ff                                  first
#define ss                                  second
#define all(v)                              v.begin(), v.end()
#define rsort(v)                            sort(v.rbegin(), v.rend())
#define debug(x)                            cerr << #x << " = " << x << nl

using namespace std;



int main(){
    #ifndef ONLINE_JUDGE
        read;
        write;
    #endif
    ll n;
    cin >> n;
    ll x;
    map<int, bool> mp;
    while(n--) {
    	cin >> x;
    	if(mp.find(x) == mp.end()) mp[x] = true;
    	else mp.erase(x);
    }
    cout << mp.size();




    return 0;

}