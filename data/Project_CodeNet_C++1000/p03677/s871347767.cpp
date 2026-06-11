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
const int mod = 1e9 + 7;
const int N = 2000005;
const int K = 50;
set < int > g1[N], g2[N];
int s1[N], s2[N], a[N], b[N], x[N];
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    int n, m;
        srand(time(NULL));
        cin >> n >> m;
 //   n = rand() % 300 + 1;
  //  m = rand() % 300 + 1;
  //  cout << n << " " << m << endl;
    for (int i = 1; i <= n; i++){
       // a[i] = rand() % m;
        cin >> a[i];
        a[i]--;
    }
    x[1] = a[1];
    for (int i = 2; i <= n; i++){
        int y;
        if (a[i] > a[i - 1]) y = a[i] - a[i - 1]; else
        y = m - (a[i - 1] - a[i]);
        x[i] = x[i - 1] + y;
    }
    int res = 1e9;
    for (int i = 0; i < 0; i++){
        int y = 0;
        for (int j = 2; j <= n; j++){
            if (a[j] > a[j - 1]){
                if (i > a[j - 1] && i <= a[j]){
                    y = y + a[j] - i + 1;
                } else y = y + a[j] - a[j - 1];
            } else{
                if (i > a[j - 1] || i <= a[j]){
                    if (i > a[j - 1]){
                        y = y + a[j] + m - i + 1;
                    } else{
                        y = y + a[j] - i + 1;
                    }
                } else y = y + m - (a[j - 1] - a[j]);
            }
        }
        res = min(res, y);
    }

   // cout << endl;
    for (int i = 2; i <= n; i++){
        if (x[i] - x[i - 1] == 1 || m == 2) continue;
        int l, r;
        if (x[i] % m > x[i - 1] % m){
            l = x[i - 1] % m + 2;
            r = x[i] % m;
        } else{
            l = x[i - 1] % m + 2;
            r = x[i] % m + m;
        }
        s1[l]++;
        s1[r + 1]--;
        int d = r - l + 1;
       // cout << d <<  endl;
        s1[r + 1] += (-d);
        s1[r + 2] += d;
    }
    int xx = 0;
    for (int i = 0; i <= m + m + m; i++){
        xx += s1[i];
        s2[i] = xx;
    }
  //  cout << xx << endl;
    xx = 0;
    int ans = 0;
    for (int i = 0; i <= m + m + m; i++){
        xx += s2[i];
        b[i] = xx;
    }
   // cout << xx << endl;
    for (int i = 0; i < m; i++){
        ans = max(ans, b[i] + b[i + m] + b[i + m + m]);
    }
   // cout << ans << endl;
    cout << x[n] - x[1] - ans;
  //  if (x[n] - x[1] - ans != res){
     //   cout << n << " " << m << endl;
  //  }
}
