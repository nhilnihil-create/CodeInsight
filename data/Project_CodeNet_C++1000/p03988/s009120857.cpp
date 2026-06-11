#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    multiset<int> st;
    int n;
    cin>>n;

    for (int i=1; i<=n; i++) {
        int x;
        cin>>x;
        st.insert(x);
    }

    int d = *st.rbegin();

    for (int i=0; i<=d; i++) {
        int dis = max(i, d-i);
        auto it = st.find(dis);
        if (it == st.end()) {
            cout<<"Impossible\n";
            return 0;
        }
        st.erase(it);
    }

    if (st.size() && *st.begin() <= (d+1)/2) cout<<"Impossible\n";
    else                                cout<<"Possible\n";

}
