#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ll long long
#define ld long double
#define zeros(x) x^(x-1)&x
#define pii pair<ll,ll>
#define cd complex<double>
#define dbg(x) cerr<<#x<<": "<<x<<endl;ll
#define Nmax 200005
#define OFF 100001
using namespace std;

ll n,m,v[Nmax], k,x;
vector<ll> d;

vector<ll> compound(vector<ll> A, vector<ll> B){
    vector<ll> ans;
    ans.resize(A.size());
    for (ll i=1;i<B.size();i++){
        ans[i] = A[B[i]];
    }
    return ans;
}

vector<ll> _pow(vector<ll> A, ll b){
    if (b==1) return A;
    if (b%2) return compound(_pow(compound(A,A), b/2), A);
    return _pow(compound(A,A), b/2);
}

int main()
{
    cin >> n;
    for (ll i=1;i<=n;i++) cin >> v[i];
    d.resize(n);
    iota(d.begin(),d.end(),0);
    cin >> m >> k;
    for (ll i=1;i<=m;i++){
        cin >> x;
        swap(d[x],d[x-1]);
    }
    d = _pow(d, k);
    cout << v[1] << '\n';
    ll ant = v[1];
    for (ll i=1;i<n;i++){
        ant += v[d[i]+1] - v[d[i]];
        cout << ant << '\n';
    }
    return 0;
}
