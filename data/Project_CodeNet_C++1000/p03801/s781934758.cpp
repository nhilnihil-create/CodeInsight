#include<bits/stdc++.h>

#define fi first
#define se second
#define all(x) (x).begin() , (x).end()
#define rall(x) (x).rbegin() , (x).rend()
#define pb push_back
#define len(x) (int)(x).size()
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
typedef long double ld;
const int N = 1e5 + 10;
#define int long long
int cnt[N] , sum[N];
void add(int *fen, int pos , int val){
    for(;pos < N; pos += (pos & -pos))
        fen[pos] += val;
}
int get(int *fen , int pos){
    int ans = 0;
    for(;pos > 0 ; pos -= (pos & -pos)){
        ans += fen[pos];
    }
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    int n;cin >> n;
    vector<int>a(n);
    for(auto &i : a)cin >> i;
    vector<int>zip = a;


    map<int,int>zipka;
    for(auto i : a)
        zipka[i] = 1;
    int cntZ = 1;
    for(auto &i : zipka)i.se = cntZ++;
    for(auto &i : zip)
        i = zipka[i];

    for(int j = 0; j < n; ++j){
        add(cnt , zip[j] , +1);
        add(sum , zip[j] , +a[j]);
    }
    map<int,int>revzip;
    for(auto &i : zipka)
        revzip[i.se] = i.fi;
    revzip[0] = 0;



    set < int > have;
    int MX = 0;
    for(int i = 0 ; i < n; ++i){
        auto it = have.upper_bound(zip[i]);
        int prev;
        if(it == have.begin())prev = 0;
        else prev = *(--it);
        /// calculate
        if(MX >= zip[i]){
                cout << 0 << '\n';
        }else{
        int cntmore = get(cnt , N-1) - get(cnt, zip[i]-1);

        ll ans = 1ll * (cntmore) * (revzip[zip[i]] - revzip[prev]);
        ll lulzsum = get(sum , zip[i]-1) - get(sum , prev-1);
        ll lulzcnt = get(cnt , zip[i]-1) - get(cnt , prev-1);
        ans += lulzsum - 1ll * lulzcnt * (revzip[prev]);
            cout << ans << '\n';
        }
        MX = max(MX , zip[i]);
        have.insert(zip[i]);
        add(cnt , zip[i] , -1);
        add(sum , zip[i] , -a[i]);

    }
    return 0;
}
