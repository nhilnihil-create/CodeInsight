#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main() {
    int N;
    cin >> N;
    vector<ll> A(N + 1, 0);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());
    ll count = 1;
    stack<ll> st;
    for (int i = 0; i < N; i++) {
        if (A[i] != A[i + 1]) {
            count = 1;
        } else {   //A[i]==A[i+1]
            count++;
            if (count % 2 == 0) {
                st.push(A[i]);
                if (st.size() == 2)break;
            }
        }
    }
    if (st.empty())cout << 0;
    else{
        ll a = st.top();st.pop();
        ll b = st.top();st.pop();
        cout << a * b;
    }
    return 0;
}