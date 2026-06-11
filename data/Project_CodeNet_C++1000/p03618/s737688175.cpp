#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define sz size
#define se second
#define fe first
#define mper make_pair
#define all(x) x.begin(), x.end()
#define mal ios_base::sync_with_stdio(NULL);cin.tie(NULL);cout.tie(NULL);
#define vl vector<ll>
#define vi vector<int>
#define vli vector <pair <ll, int> >
#define vll vector <pair <ll, ll> >
#define vii vector <pair <int, int> >
using namespace std;

const ll MAXN = 2e5 + 100;
string s;

map <char, ll> mp;

void solve() {

    vector < pair <char, int> > g;

    cin >> s;
//    n = s.sz();

    reverse(all(s));

    ll ans = 0;

    for(int i = 0; i < s.sz(); ++i) {

        ll l = s.sz() - i - 1;

        ans += s.sz() - l - 1;

        if(mp[s[i]]) {

            ans -= mp[s[i]];

        }

        mp[s[i]]++;

    }

    cout << ans + 1;

}

int main(){

mal
//freopen("ladder.in", "r", stdin);
//freopen("ladder.out", "w", stdout);

ll tt = 1;


while(tt--) {

    solve();

}

return 0;
}

