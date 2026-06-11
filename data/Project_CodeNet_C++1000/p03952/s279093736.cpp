#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define F first
#define S second
#define int long long
#define ll long long
//#define int  unsigned long long
#define pb push_back
//#define double long double

using namespace std;
using namespace __gnu_pbds;
typedef  tree< int , null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const int mod = 998244353;
const int N = 1000005;
const int K = 25;
int ans[N];
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    int n, x;
    cin >> n >> x;
    if (x == n + n - 1 || x == 1){
        cout << "No";
        return 0;
    }
    if (n == 2){
        cout << "Yes" << endl;
        cout << "1 2 3";
        return 0;
    }
    set < int > s;
    for (int i = 1; i <= n + n - 1; i++) s.insert(i);
    ans[n] = x;
    s.erase(x);
    ans[n + 1] = x + 1;
    s.erase(x + 1);
    ans[n - 1] = x - 1;
    s.erase(x - 1);
    if (x == n + n - 2){
        ans[n + 2] = x - 2;
        s.erase(x - 2);
    }
    else{
        ans[n - 2] = x + 2;
        s.erase(x + 2);
    }
    for (int i = 1; i <= n + n - 1; i++){
        if (ans[i] == 0){
            ans[i] = *s.begin();
            s.erase(s.begin());
        }
    }
    cout << "Yes" << endl;
    for (int i = 1; i <= n + n - 1; i++) cout << ans[i] << " ";
}
