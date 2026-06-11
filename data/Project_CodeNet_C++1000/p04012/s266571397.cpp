#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, n) for (int i = 1; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
signed main()
{
    string w;
    cin >> w;

    unordered_map<char, int> us;
    rep(i, w.size()) us[w[i]] = 0;
    rep(i, w.size()) us[w[i]]++;

        
    for(auto kv : us) {
        if (kv.second % 2 == 1){
            put("No");
            return 0;
        }
    } 
    put("Yes");
    return 0;
}