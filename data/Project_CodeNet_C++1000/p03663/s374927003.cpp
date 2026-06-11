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
const int N = 1200000;
vector < int > v[N];
int used[N], l[N], t[N], p[N];
int ask(int x){
    cout << "? " << x << endl;
    fflush(stdout);
    string s;
    cin >> s;
    return (s == "Y");
}
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    int res = 0;
    while(1){
        int l = 1;
        if (res != 0) l = 0;
        int r = 10;
        while(r - l > 1){
            int mid = (r + l) / 2;
            if (ask(10 * res + mid)) l = mid; else r = mid;
        }
        if (l == 9){
            int z = 1;
            if (res != 0) z = 0;
            if (ask(100 * res + 10 * z) == 0){
                for (int i = z; i <= 9; i++){
                    if (ask(100 * res + i * 10)){
                        cout << "!" << 10 * res + i;
                        fflush(stdout);
                        return 0;
                    }
                }
            } else{
                if (z == 0){
                    int x = res;
                    while(x < 1e15) x = x * 10;
                    if (ask(x)){
                        cout << "! " << 10 * res;
                        return 0;
                    }
                } else{
                    if (ask(100000000000000000)){
                        cout << "! 1";
                        return 0;
                    }

                }
            }
        }
        res = res * 10 + l;
    }
}
