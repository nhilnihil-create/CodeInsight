/*------------------------------------
........Bismillahir Rahmanir Rahim....
..........created by Abdul Aziz.......
------------------------------------*/
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <unordered_map>
#include <queue>
#define   mod  998244353
#define   int  long long 
#define   ld long double
#define   pb push_back
#define  sz(x)  (int)x.size()
#define  ff first
#define  ss second
#define  pii  pair<int,int>
using namespace std;

inline void solve(){ 
    int n,m;
    cin>>n>>m;
    vector <string> a(n),b(n);
    for (int i=0;i<n;i++) cin>>a[i];
    for (int i=0;i<m;i++) cin>>b[i];
    bool ok=false;
    for (int i=0;i<=n-m;i++){ // row.... 
        for (int j=0;j<=n-m;j++){ // column.... 
            ok=true;
            for (int k=0;k<m;k++){
                for (int l=0;l<m;l++){
                    if (a[i+k][j+l] != b[k][l]) ok=false;
                    //cout << a[i+k][j+l] << " ";
                }
                //cout << endl ; 
                if (!ok) break;
            }
            if (ok) break;
        }
        if (ok) break;
    }
    if(ok) cout << "Yes"<< endl;
    else cout << "No"<< endl;
}

signed main()
{
    int n=1;  //cin>>n;
    while (n--) solve();
    return 0;
}
// 10111101000010100 
// https://codeforces.com/contest/1363/problem/B