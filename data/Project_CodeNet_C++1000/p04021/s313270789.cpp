#include<bits/stdc++.h>
using namespace std;

int main() {
    int64_t N;
    cin >> N;
    vector<int64_t> A(N);
    set<int64_t> st;
    for (int64_t& a : A) {
        cin >> a;
        st.insert(a);
    }

    int64_t counter = 0;
    map<int64_t, int64_t> mp;
    for (int64_t e : st) {
        mp[e] = counter++;
    }

    int64_t num = 0;
    for (int64_t i = 0; i < N; i++) {
        A[i] = mp[A[i]];
        num += (i + A[i]) % 2;
    }

    cout << num / 2 << endl;
}