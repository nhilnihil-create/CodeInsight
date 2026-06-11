#include<bits/stdc++.h>

using namespace std;
using ll = long long int;
#define long ll

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);

    string s;
    cin >> s;
    ll n = s.size();

    vector<ll> pos = {n};
    {
        set<char> st;
        for(ll i=n-1; i>=0; i--) {
            st.insert(s[i]);
            if(st.size() == 26) {
                st.clear();
                pos.push_back(i);
            }
        }
    }

    string r;
    {
        ll i = 0;
        if(pos.back() == 0) {
            r += 'a';
            while(i < n && s[i++] != 'a');
            pos.pop_back();
        }

        while(i < n) {
            set<char> st;
            while(i < pos.back()) st.insert(s[i++]);
            pos.pop_back();

            char c;
            for(c='a'; c<='z'; c++)
                if(!st.count(c)) break;

            while(i < n && s[i++] != c);
            r += c;
        }
    }
    cout << r << endl;

}
