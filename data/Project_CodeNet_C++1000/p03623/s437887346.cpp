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

    ll a,b,x;
    cin>>x>>a>>b;
    ll d1 = abs(x-a);
    ll d2 = abs(x-b);
    if (d1<d2) cout << "A\n";
    else cout << "B\n";
}
