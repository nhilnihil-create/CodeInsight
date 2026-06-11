#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+7;
int l[N], r[N], a[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    for (int i=1; i<=n; i++)    cin>>a[i];

    stack<int> st;
    st.push(0);

    for (int i=1; i<=n; i++) {
        while (a[st.top()] > a[i])  st.pop();
        l[i] = st.top();
        st.push(i);
    }

    st = stack<int>();
    st.push(n+1);

    for (int i=n; i>0; i--) {
        while (a[st.top()] > a[i])  st.pop();
        r[i] = st.top();
        st.push(i);
    }

    long long ans = 0;
    for (int i=1; i<=n; i++) {
        ans += 1LL*a[i]*(r[i]-i)*(i-l[i]);
    }
    cout<<ans<<endl;
}
