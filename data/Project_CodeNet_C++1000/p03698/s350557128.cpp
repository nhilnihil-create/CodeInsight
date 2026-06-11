#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    string s;
    cin >> s;
    set<char> st;
    rep(i,s.size()) {
        if(st.count(s[i])==1) {cout << "no" << endl; return 0;}
        st.insert(s[i]);
    }
    cout << "yes" << endl;
    return 0;
}