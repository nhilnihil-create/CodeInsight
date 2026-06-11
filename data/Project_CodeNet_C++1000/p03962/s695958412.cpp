#include <bits/stdc++.h>
typedef long long ll;
#define rep(i, a, n) for (ll i = a; i < (ll)n; ++i)
const int MOD = 1000000007;
using namespace std;

int main(void)
{
    int a, b, c;
    set<int> st;
    rep(i, 0, 3)
    {
        int tmp;
        cin >> tmp;
        st.insert(tmp);
    }
    cout << st.size() << endl;
}