#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<ll> v(n);
    rep(i, n) cin >> v[i];
    sort(v.begin(), v.end(), greater<ll>());
    ll sum = 0;
    rep(i, a) sum += v[i];
    ld ave = (ld)sum / a;
    cout << setprecision(10);
    cout << ave << endl;

    ll p = 1;
    if(v[a - 1] != v[a]){
        cout << p << endl;
    }else{
        int over = 0;
        for(int i = a; i < n; i++) if(v[i] == v[a - 1]) over++;
        int below = 0;
        for(int i = a - 1; i >= 0; i--) if(v[i] == v[a - 1]) below++;
        
        ll ans = 0;
        vector<ll> nck(over+below+1, 1);
        for(int i = 1; i < over+below+1; i++){
            nck[i] = nck[i - 1];
            nck[i] *= (over+below+1-i);
            nck[i] /= i;
        }

        if(v[a - 1] == v[0]){
            for(int k = below; k <= below + min(over, b - a); k++){
                ans += nck[k];
            }
            cout << ans << endl;
        }else{
            ans = nck[below];
            cout << ans << endl;
        }
        
    }
    
}