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
const int N = 1e5 + 7;
bool first_win(vector <int> a) {
    int n = a.size();
    vector <int> pref(n + 1), post(n + 1);
    for (int i = 0; i < n; ++i)
        pref[i + 1] = __gcd(pref[i], a[i]);
    for (int i = n - 1; i >= 0; --i)
        post[i] = __gcd(post[i + 1], a[i]);
    int sum = 0;
    for (int i = 0; i < n; ++i)
        sum += a[i];
    if ((sum - n) % 2 == 1)
        return 1;
    for (int i = 0; i < n; ++i) {
        if (a[i] > 1) {
            int d = __gcd(__gcd(pref[i], post[i + 1]), a[i] - 1);
            if (d % 2 == 0) {
                vector <int> b = a;
                for (int j = 0; j < n; ++j) 
                    b[j] /= d;      
                if (!first_win(b))
                    return 1;
            }    
        }
    }   
    return 0;
}   

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    if (first_win(a))
        cout << "First" << endl;
    else
        cout << "Second" << endl;
}   