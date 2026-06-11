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
    
    cin>>n;
    set<ll> s;
    u.clear();
    for (int i=0;i<n;i++) {
        cin>>m;
        u[m]++;
        s.insert(m);
    }
    ll f=-1;
    ll se=-1;
    for (set<ll>::reverse_iterator itr=s.rbegin();itr!=s.rend();itr++) {
        if (u[*itr] >= 4 && f == -1) {
            cout << (*itr)*(*itr) << endl;
            exit(0);
        }
        if (u[*itr]>=2) {
            if (f == -1) f = *itr;
            else if (se == -1) {
                se = *itr;
                break;
            }
        }
    }
    if (se==-1) cout << "0\n";
    else cout << f*se << endl;
 }
