    #include <bits/stdc++.h>
    #define rep(i, n) for (ll i = 0; i < (n); i++)
    #define all(x) (x).begin(), (x).end()
    using ll = long long;
    using namespace std;
    template <typename T> using vec = std::vector<T>;
     
    int main() {
        int N;
        cin >> N;
        
        unordered_map<int,int> mp;
        vec<ll> a2;
        vec<ll> a4;
        rep(i, N){
            int a;cin >> a;
            ++mp[a];
            if(mp[a] == 2) a2.push_back(a);
            if(mp[a] == 4) a4.push_back(a);
        }
        sort(a2.rbegin(),a2.rend());
        sort(a4.rbegin(),a4.rend());
        ll ans = 0;
        if(a2.size()>=2) ans = a2[0]*a2[1];
        if(a4.size()>=1) ans = max(ans,a4[0]*a4[0]);
        cout << ans << endl;
    }