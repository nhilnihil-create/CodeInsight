#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    set<int> st;
    int A;
    for (int i = 0; i < N; i++) {
        cin >> A;
        if (st.find(A) == st.end()) st.insert(A);
        else st.erase(A);
    }
    cout << st.size() << endl;
}