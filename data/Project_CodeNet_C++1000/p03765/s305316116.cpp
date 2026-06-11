#include<bits/stdc++.h>

#define fi first
#define se second
#define all(x) (x).begin() , (x).end()
#define rall(x) (x).rbegin() , (x).rend()
#define pb push_back
#define len(x) (int)(x).size()

typedef long long ll;
typedef long double ld;

using namespace std;

vector < int > input(){
    string s;cin >> s;
    vector < int > ans(len(s));
    for(int i = 0; i < len(s); ++i)
        ans[i] = (s[i]=='A'?1:2);
    return ans;
}
signed main(){
    vector<int> s = input() , t = input();
    vector < int > prefs(len(s) + 1) , preft(len(s) + 1);
    for(int i = 0; i < len(s); ++i)
        prefs[i + 1] = prefs[i] + s[i];
    for(int j = 0 ; j < len(t); ++j)
        preft[j + 1] = preft[j] + t[j];
    int q;cin >> q;
    while(q--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if((prefs[b]-prefs[a-1])%3==(preft[d]-preft[c-1])%3)
            cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
