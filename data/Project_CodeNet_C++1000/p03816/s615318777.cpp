#include <bits/stdc++.h>
#define MAXN 100100
#define pii pair<int, int>
#define pll pair<long long, pair<long long, long long>>
#define ff first
#define ss second
#define ll long long
#define in_range(x, y, n) (x >= 0 and x < n and y >= 0 and y < n)
using namespace std;
const int mod = 1e9 + 7;
const ll oo = 1e17 + 7;


int main()
{
    ios_base::sync_with_stdio(false);
    map<int, int> st;
    int n, aux;

    cin >> n;
    vector<pii> v(MAXN, {0, 0});


    for (int i=0; i<n; i++){
        cin >> aux;
        v[aux].ff--;
        v[aux].ss = aux;
    }

    sort(v.begin(), v.end());

    for (auto& x : v){
        // cout << x.ff << " ";
        while (x.ff <= -3) x.ff+=2;
    }
    // cout << endl;
    sort(v.begin(), v.end());


    int carry = 0;

    for (auto& x : v){
        // cout << x.ff << " ";
        if (x.ff < 0) x.ff += carry, carry = 0;
        else continue;
        if (x.ff == -2)x.ff++, carry = 1;
    }
    // cout << endl;

    int ans = 0;

    for (auto& x : v){
        ans += x.ff;
    }

    cout << -ans << endl;
    return 0;
}