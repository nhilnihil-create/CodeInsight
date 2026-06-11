#include<bits/stdc++.h>


#define fi first
#define se second
#define all(x) (x).begin() , (x).end()
#define rall(x) (x).rbegin() , (x).rend()
#define pb push_back
#define len(x) (int)(x).size()

typedef long long ll;
typedef long double ld;

using namespace std;
const int N = 1e5 + 10 , LG = 18;
int x[N] , f[N], bin[N][LG];
signed main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    int n;cin >> n;
    for(int i =  0 ;  i < n; ++i)cin >> x[i];
    int L;cin >> L;
    /// not more that L per a day
    /// he must to stay al hotel for night
    /// okay we have Q queries v
    /// okay let's f[i] - will be next hotel after ower
    /// let's do binary lifiting for it and understand when f[f[f[f[fi]]]] >= b
    for(int i =  0 ;   i < n; ++i){
        int nxt = upper_bound(x , x + n , x[i] + L) - x - 1;
        f[i] = nxt;
    }
//    for(int i = 0 ; i < n; ++i)
//        cout << f[i] << ' ';
//    cout << " MEM \n";
    for(int i =  0 ; i  < n; ++i)
        bin[i][0] = f[i];
    for(int st = 1; st < LG; ++st)
        for(int i = 0  ; i < n; ++i)
            bin[i][st] = bin[bin[i][st-1]][st-1];
    int q;cin >> q;
    while(q--){
        int a , b;cin >> a >> b;
        --a , --b;
        if(a > b)swap(a , b);
        int ans = 0;
        for(int i = LG - 1; i >= 0 ; --i){
            if(bin[a][i] < b)
                a = bin[a][i] , ans += (1 << i);
        }
        ans += 1;
        cout << ans << '\n';
    }
    return 0;
}
