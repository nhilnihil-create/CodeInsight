#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define mod2 998244353
#define pii pair<ll,ll>
#define pb push_back

#define debug(a) { cout << #a << " = " << a << endl;}

void sep() {
    cout << "-------------BLOCK-----------------\n";
}

template<typename T>
void debugv(vector<T> arr) {
    for (auto t: arr)
        cout << t << " ";
    cout << "\n";
}

template<typename T>
void debugarr(T arr, int n) {
    for (int i=0;i<n;i++) cout << arr[i] << " ";
    cout << "\n";
}

ll __min(ll a, ll b) {
    return a < b ? a : b;
}

ll __max(ll a, ll b) {
    return a > b ? a : b;
}

const int maxn = 1e5+1;
ll arr[maxn], n, m, t, k, q;
unordered_map<ll,ll> u;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    

    // two cases
    // a  bb 
    // a  cc

    cin>>n;
    string s1;
    string s2;
    cin>>s1>>s2;
    ll ans=1;
    
    // resolve first part
    ll cp=0;
    ll prev;
    if (s1.size() > 1 &&  s1[0] == s1[1] && s2[0] == s2[1]) {
        // this is 2nd case
        prev=2;
        ans = 6;
        cp=2;
    } else {
        prev=1;
        ans=3;
        cp=1;
    }

    while (cp<n) {
        if (cp+1 < n && s1[cp] == s1[cp+1]  && s2[cp] == s2[cp+1]) {
            // this is 2nd case
            if (prev==2)
                ans=(ans*3)%mod;
            else
                ans=(ans*2)%mod;
            prev=2;
            cp+=2;
        } else {
            if (prev==2)
                ans*=1;
            else
                ans=(ans*2)%mod;
            prev=1;
            cp++;
        }
    }
    ans %= mod;
    if (ans < 0) ans += mod;
    cout << ans << endl;
}
