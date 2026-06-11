#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
using ld = long double;
template<typename T> using v2 = vector<vector<T>>;
template<typename T> inline v2<T> fill(int r, int c, const T& t){ return v2<T>(r, vector<T>(c, t)); }
#define F first
#define S second

ll choose(int n, int k){
    if(k > n) return 0;
    if(k*2 > n) k = n-k;
    if(!k) return 1;

    ll ans = n;
    for(int i = 2; i <= k; ++i){
        ans *= n-i+1;
        ans /= i;
    }
    return ans;
}

void solve(){
    int n,a,b;
    cin>>n>>a>>b;
    vector<ll> v(n);
    for(int i = 0; i < n; ++i){
        cin >> v[i];
    }
    sort(v.begin(), v.end(), greater<ll>());

    ll last = v[a-1];

    int start = a-1;
    while(start-1 >= 0 && v[start-1]==last) --start;

    int end = a-1;
    while(end+1 < n && v[end+1]==last) ++end;

    int l = end-start+1;
    if(start==0){
        ll ways = 0;
        for(int i = a; i <= min(l, b); ++i){
            ways += choose(l, i);
        }
        cout << fixed <<setprecision(9)<<(ld)v[0] << '\n' << ways << '\n';
    }
    else{
        int need = a-start;
        ll ways = choose(l, need);
        ll sum = 0;
        for(int i = 0; i < a; ++i) sum+=v[i];
        ld avg = (ld)sum/a;
        cout << fixed <<setprecision(9)<<avg << '\n' << ways << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}