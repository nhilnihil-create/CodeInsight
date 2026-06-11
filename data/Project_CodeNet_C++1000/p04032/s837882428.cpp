    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;

    void solve() {
        string s;
        cin >> s;
        vector<ll> v[30];
        ll n = s.length();
        for(ll i = 0; i < n; i++) v[s[i] - 'a'].push_back(i);
        for(ll i = 0; i < 30; i++) sort(v[i].begin(), v[i].end());
        for(ll i = 0; i < 30; i++) {
            if(v[i].size() < 2) continue;
            for(ll j = 1; j < v[i].size(); j++) if(v[i][j] - v[i][j-1] < 3){
                cout << v[i][j-1] + 1 << " " << v[i][j] + 1 << endl;
                return;
            }
        }
        cout << -1 << " " << -1 << endl;
    }

    int main() {
      cin.sync_with_stdio(0); cin.tie(0);
      cin.exceptions(cin.failbit);
      //ll ti;   cin >> ti;  while(ti--)
      solve();
      return 0;
    }
