#include<bits/stdc++.h>

using namespace std;

int main(void) {
    long n, m;
    cin >> n >> m;

    vector<vector<int>> G(n);

    int s = 0;
    for(int i=0; i<m; i++) {
        int a,b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
        s = a;
    }
    int ss = s;

    vector<int> res = {s};
    set<int> st; st.insert(s);

    while(1) {
        for(auto v: G[s]) {
            if(st.count(v)) continue;
            s = v;
            res.push_back(s);
            st.insert(s);
            goto nxt;
        }
        break;
nxt:
        ;
    }

    vector<int> ser;
    s = ss;
    while(1) {
        for(auto v: G[s]) {
            if(st.count(v)) continue;
            s = v;
            ser.push_back(s);
            st.insert(s);
            goto nxt2;
        }
        break;
nxt2:
        ;
    }

    cout << ser.size() + res.size() << endl;
    reverse(ser.begin(), ser.end());
    for(auto x: ser) cout << x+1 << endl;
    for(auto x: res) cout << x+1 << endl;
}
