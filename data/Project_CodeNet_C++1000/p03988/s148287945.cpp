#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
     
using namespace std;
     
typedef long long ll;
typedef pair<int, int> pii;
     
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
     
mt19937 rnd(chrono::steady_clock().now().time_since_epoch().count());

const int N = 105;
int cnt[N];

void res(bool t){
    if(t)
        cout << "Possible\n";
    else
        cout << "Impossible\n";
    exit(0);
}

int main(){
    fastIO;
    int n;
    cin >> n;
    if(n == 2)
        res(true);
    int a;
    int mn = n;
    int mx = 0;
    for(int i = 1; i <= n; i ++ ){
        cin >> a;
        mn = min(mn, a);
        mx = max(mx, a);
        cnt[a] ++ ;
    }
    if(cnt[mn] > 2)
        res(false);
    int p = mn + 1;
    int z = mn;
    if(cnt[mn]==2) z--;
    for(int i = 0 ; i < z; i ++ ){
        if(cnt[p] < 2)
            res(false);
        p ++ ;
    }
    while(p < N){
        if(cnt[p] > 0)
            res(false);
        p ++ ;
    }
    res(true);
    return 0;
}