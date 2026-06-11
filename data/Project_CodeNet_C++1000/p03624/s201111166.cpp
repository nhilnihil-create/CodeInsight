#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
    string S;
    cin >> S;

    set<char> st;
    for (char c='a'; c<='z'; ++c)
        st.insert(c);

    for (size_t i=0; i<S.size(); ++i) {
        st.erase(S[i]);
    }

    //for (auto &c: st) cout << c << ", ";
    //cout << endl;
    if (st.size() == 0) {
        cout << "None" << endl;
    }
    else {
        auto iter = st.begin();
        cout << *iter << endl;
    }
}
