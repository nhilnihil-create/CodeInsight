#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
ll mod = 1000000007;
 
int main() {
    int n, x;
    cin >> n >> x;

    if(x == 1 || x == 2*n-1) {
        cout << "No" << "\n";
        return 0;
    }

    cout << "Yes" << "\n";

    if(n == 2) {
        for(int i = 1; i <= 3; i++) {
            cout << i << "\n";
        }
        return 0;
    }

    vector<int> v(2*n-1);
    set<int> st;

    for(int i = 1; i <= 2*n-1; i++) {
        st.insert(i);
    }

    v[n-2] = x-1;  v[n-1] = x;  v[n] = x+1;
    st.erase(x-1);  st.erase(x);  st.erase(x+1);

    if(1 <= x-2) {
        v[n+1] = x-2;
        st.erase(x-2);
    } 
    else {
        v[n-3] = x+2;
        st.erase(x+2);
    }

    rep(i, 2*n-1) {
        if(!v[i]) {
            v[i] = *st.begin();
            st.erase(st.begin());
        }
        cout << v[i] << "\n";
    }

    return 0;
}