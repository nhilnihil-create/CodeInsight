#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    int a, b;
    cin >> a >> b;
    if (a <= 0 && 0 <= b) {
        cout << "Zero" << endl;
    }   
    else {
        b = min(b, -1ll);
        int cnt = max(0ll, b - a + 1);
        if (cnt & 1)
            cout << "Negative" << endl;
        else
            cout << "Positive" << endl;                    
    }   

}