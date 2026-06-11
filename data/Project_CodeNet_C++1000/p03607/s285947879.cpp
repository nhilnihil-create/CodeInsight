#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    set<int>st;
    while (n--) {
        int a;
        cin >> a;
        if (st.count(a)) {
            st.erase(st.find(a));
        }
        else
            st.insert(a);
    }
    cout << st.size() << endl;
}