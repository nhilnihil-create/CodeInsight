#include<bits/stdc++.h>


#define fi first
#define se second
#define all(x) (x).begin() , (x).end()
#define rall(x) (x).rbegin() , (x).rend()
#define pb push_back
#define len(x) (int)(x).size()
#define mkp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;


const int maxn = 3e5 + 10 , inf = 1e9;
vector < int > fenwick[maxn];
int get(int pref , int l , int r){
    int ans = 0;
    for(;pref > 0; pref -= (pref & -pref)){
        ans += upper_bound(all(fenwick[pref]) , r) - lower_bound(all(fenwick[pref]) , l);
    }
    return ans;
}
int ask(int l , int r , int l1 , int r1){
    return get(r , l1, r1) - get(l - 1 , l1 , r1);
}
void add(int x , int y){
    for(;x < maxn; x += (-x & x)){
        fenwick[x].pb(y);
    }
}

signed main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    int n , m;cin >> n >> m;
    vector < pii > lines(n);
    for(auto &i : lines)cin >> i.fi >> i.se;
    sort(all(lines));

    for(int i = 0 ; i < n; ++i)
        add(i+1 , lines[i].se);
    for(int i = 0 ; i < maxn; ++i)
        sort(all(fenwick[i]));
    for(int i = 1; i <= m; ++i){
        int ans = 0;
        int alr = 0;
        int pos = 0;
        while(pos <= m){
            int prev = alr;
            alr = upper_bound(all(lines) , mkp(pos , inf)) - lines.begin();
            if(prev <= alr - 1){
//                cout << " FOR " << i << ' ' << prev << ' ' << alr - 1 << ' ' << pos << ' ' << m << '\n';
                ans += ask(prev +1 , alr - 1 +1, pos, m);
            }
            pos += i;
        }
        cout << ans << '\n';
    }
    return 0;
}
