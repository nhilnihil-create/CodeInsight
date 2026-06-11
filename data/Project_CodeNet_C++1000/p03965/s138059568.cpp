    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;

    void solve() {
        string s;
        cin >> s;
        stack<char> st;
        for(ll i = 0; i < s.length(); i++) {
            if(st.empty()) st.push(s[i]);
            else {
                if(st.top() == 'g' && s[i] == 'p') st.pop();
                else st.push(s[i]);
            }
        }
        //cout << st.size() << endl;
        ll p = 0, r = 0;
        while(!st.empty()) (st.top() == 'p' ? p++:r++), st.pop();
        ll cnt = -(p+1)/2 + (p%2 ? (r+1)/2 : r/2);
        cout << cnt << endl;
    }

    int main() {
      cin.sync_with_stdio(0); cin.tie(0);
      cin.exceptions(cin.failbit);
      //ll ti;   cin >> ti;  while(ti--)
      solve();
      return 0;
    }
