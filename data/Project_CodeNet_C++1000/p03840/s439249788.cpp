#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
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
    int ai, ao, at, aj, al, as, az;
    cin >> ai >> ao >> at >> aj >> al >> as >> az;

    int ans = 0;
    for (int i = 0; i < 1000 * 1000; ++i) {        
        ans = max(ans, (ai/2) * 2 + ao * 1 + (aj/2)*2 + (al/2)*2 + i*3);
        if (!ai || !aj || !al) {
            break;
        }   
        --ai; 
        --aj;
        --al;
    }   
    cout << ans << endl;
}