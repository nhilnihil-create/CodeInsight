#include <bits/stdc++.h>

#define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL)
#define int long long
#define endl '\n'

using namespace std;

const int N = 2e5 + 77;

int32_t main()
{
    fast;
    int k ,t ; cin >> k >> t ;
    int mx = -1;
    for(int i = 0 ; i< t ; ++i){
        int a ; cin >> a;
        mx = max(mx,a);
    }
    cout << max(0LL,2*mx-k-1) << endl;
    return 0;
}