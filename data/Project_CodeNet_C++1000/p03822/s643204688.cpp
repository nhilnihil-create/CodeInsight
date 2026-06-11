#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ll long long
#define ld long double
#define zeros(x) x^(x-1)&x
#define pii pair<ll,ll>
#define cd complex<double>
#define dbg(x) cerr<<#x<<": "<<x<<endl;ll
#define Nmax 400005
#define OFF 100001
#define MOD 1000000007
using namespace std;

ll n, x;
vector<int> v[Nmax];

int dfs(int nod){
    int ans = 0, nr = 0;
    vector<int> L;
    for (auto it : v[nod]){
        L.push_back(dfs(it));
    }
    sort(L.begin(),L.end());
    while (!L.empty()){
        nr++;
        ans = max(ans, nr + L.back());
        L.pop_back();
    }
    return ans;
}

int main()
{
    cin >> n;
    for (int i=2;i<=n;i++){
        cin >> x;
        v[x].push_back(i);
    }

    cout << dfs(1) << '\n';

    return 0;
}
