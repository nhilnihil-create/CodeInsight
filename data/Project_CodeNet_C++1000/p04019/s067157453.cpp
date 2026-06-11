#include<bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin>>s;

    set<char> st;
    for (char c: s) st.insert(c);

    bool good = true;
    if (st.count('N') + st.count('S') == 1) good = false;
    if (st.count('E') + st.count('W') == 1) good = false;

    if (good)   cout<<"Yes\n";
    else        cout<<"No\n";
}
