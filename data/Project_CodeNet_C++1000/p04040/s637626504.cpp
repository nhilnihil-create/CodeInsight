#include <bits/stdc++.h>

using namespace std;

const long long mod = 1000000007; 

long long Pow(long long a, long long b) {
    long long cnt, ret; 
    cnt = a; 
    ret = 1; 
    while (b) {
        if (b & 1) ret = ret * cnt % mod;
        cnt = cnt * cnt % mod; 
        b >>= 1;  
    }
    return ret; 
}

long long inv(long long a) {
    return Pow(a, mod - 2); 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15); 
    int n, m, a, b; 
    cin >> n >> m >> a >> b; 
    vector<long long> st, ed; 
    st.resize(m - b);
    ed.resize(m - b); 
    st[0] = 1;
    for (int i = n - a + b - 1; i >= n - a; --i) st[0] = st[0] * i % mod; 
    for (int i = 1; i <= b; ++i) st[0] = st[0] * inv(i) % mod; 
    for (int i = 1; i < m - b; ++i) {
        st[i] = st[i - 1] * (n - a + b + i - 1) % mod; 
        st[i] = st[i] * inv(b + i) % mod; 
    }
//    for (int i = 0; i < m - b; ++i)
//        cout << st[i] << endl; 
    ed[m - b - 1] = 1;
    for (int i = m - b - 2; i >= 0; --i) {
        ed[i] = ed[i + 1] * (a + m - b - 2 - i) % mod; 
        ed[i] = ed[i] * inv(m - b - 1 - i) % mod; 
    } 
//    for (int i = 0; i < m - b; ++i)
//        cout << ed[i] << endl; 
    long long sum = 0; 
    for (int i = 0; i < m - b; ++i) {
        sum = (sum + st[i] * ed[i] % mod) % mod; 
    }
    cout << sum << endl; 
    return 0; 
}