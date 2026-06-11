#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define agewari(a, b) ((ll)a + ((ll)b - 1)) / b
const int MOD = 1000000007;
const long long INF = 1LL << 60;
using Graph = vector<vector<ll>>;

int main()
{
    ll n, k;
    cin >> n >> k;
    map<ll, ll> M;
    rep(i, n)
    {
        ll a, b;
        cin >> a >> b;
        M[a] += b;
    }

    ll tmp = 0;
    ll rui = 0;
    for (auto m : M)
    {
        tmp=m.first;
        rui+=m.second;
        if(rui>=k){
            cout<<tmp<<endl;
            return 0;
        }
    }
}