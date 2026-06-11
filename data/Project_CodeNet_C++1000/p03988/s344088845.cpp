#include <bits/stdc++.h>
#define For(i, a, b) for(int (i)=(a); (i)<(b); ++(i))
#define rFor(i, a, b) for(int (i)=(a)-1; (i)>=(b); --(i))
#define rep(i, n) For((i), 0, (n))
#define rrep(i, n) rFor((i), (n), 0)
#define fi first
#define se second
using namespace std;
typedef long long lint;
typedef pair<int, int> pii;
typedef complex<double> xy_t;

const lint mod = 1e9 + 7;

int main(){
    int n;
    scanf("%d", &n);
    map<int, int> mp;
    int L = 0;
    rep(i, n){
        int a;
        scanf("%d", &a);
        ++mp[a];
        L = max(L, a);
    }
    
    rep(i, L+1){
        int d = max(i, L-i);
        if(mp[d] == 0){
            printf("Impossible\n");
            return 0;
        }
        else --mp[d];
    }
    
    int m = (L-1)/2 + 2;
    for(auto itr=mp.begin(); itr!=mp.end(); ++itr){
        if(itr->se && itr->fi < m){
            printf("Impossible\n");
            return 0;
        }
    }
    
    printf("Possible\n");
}