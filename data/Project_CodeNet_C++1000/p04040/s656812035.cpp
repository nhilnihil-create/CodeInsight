#include<bits/stdc++.h>

#define fi first
#define se second
#define ll long long
#define pb push_back
#define mp make_pair
#define mt make_tuple

using namespace std;

const ll MOD = 1e9 + 7;

ll prvi[100010];
ll drugi[100010];
ll fak[200010];


ll mul(ll a, ll b)
{
    a %= MOD;
    b %= MOD;
    return (a*b)%MOD;
}

ll inverz(ll a, ll st)
{
    if(st == 0) return 1;
    ll res = inverz(a, st/2);
    res %= MOD;
    res *= res;
    res %= MOD;
    if(st % 2 == 1)
    {
        res *= a;
        res %= MOD;
    }
    return res;
}

ll fakt(ll a)
{
    /*if(a < 0 || a > 100000)
    {
        cout << a;
        exit(0);
        return 1;
    }*/
    return fak[a];
}

ll pref()
{
    fak[0] = 1;
    for(ll i = 1; i <= 200000; i++)
        fak[i] = mul(fak[i-1], i);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    pref();

    ll FiMod = MOD - 1;
    //cout << mul(15, inverz(5, FiMod-1));
    ll h, w, a, b;
    cin >> h >> w >> a >> b;


    prvi[1] = 1;
    ll hTren = 1;
    ll wTren = b;
    for(int i = 2; i <= h - a; i++)
    {
        //prvi[i] = prvi[i-1]*(hTren+wTren-1)*inverz(h);
        prvi[i] = mul(prvi[i-1], hTren + wTren - 1);
        prvi[i] = mul(prvi[i], inverz(hTren, FiMod - 1));
        hTren = i;
    }
    wTren = w - b;
    hTren = h;
    //cout << hTren + wTren - 2 << "haha\n ";

    drugi[1] = fakt(hTren + wTren - 2);
    drugi[1] %= MOD;
    drugi[1] = mul(drugi[1], inverz(fakt(wTren - 1), FiMod - 1));
    drugi[1] = mul(drugi[1], inverz(fakt(hTren - 1), FiMod - 1));

    for(int i = 2; i <= h - a; i++)
    {
        //prvi[i] = prvi[i-1]*(hTren+wTren-1)*inverz(h);
        drugi[i] = mul(drugi[i-1], hTren - 1);
        drugi[i] = mul(drugi[i], inverz(hTren + wTren - 2, FiMod - 1));
        hTren = h - i + 1;
    }
    ll sum = 0;

    /*for(int i = 1; i <= h - a; i++)
    {
        cout << prvi[i] << " " << drugi[i] << "\n";
    }*/
    for(int i = 1; i <= h - a; i++)
    {
        sum += mul(prvi[i], drugi[i]);
        sum %= MOD;
    }
    cout << sum;
    return 0;
}
