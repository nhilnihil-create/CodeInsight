#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>

using namespace std;
#define REP(i,n) FOR(i,0,n)
#define FOR(i,a,b) for(long long i=(a),i##Len_=(b);i<i##Len_;i++)
typedef long long ll;
static const ll MOD = 1000000007;
static const ll INF = 1000000000000000000LL;



int main()
{
    ll N;

    cin >> N;

    ll a[N];
    ll x = 0;

    ll tmp = 0;

    ll iMin = INF;

    REP(i,N)
    {
        cin >> a[i];
        tmp += a[i];

    }

    REP(i,N-1)
    {
        x += a[i];

        iMin = min(iMin,abs(tmp -2*x));

    }

    cout << iMin << endl;

}

