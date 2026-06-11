#include <bits/stdc++.h>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define REPV(iter, v) for(auto (iter)=(v).begin(); (iter)!=(v).end();++(iter))
#define ALL(v) (v).begin(),(v).end()

#define MOD 1000000007

using namespace std;

typedef long long ll;

int main()
{
    ll N;
    cin >> N;
    vector<ll> p(N);
    REP(i, N)
    {
        cin >> p[i];
        p[i]--;
    }

    vector<ll> a(N), b(N);
    REP(i, N)
    {
        a[i] = 1 + i * N;
        b[N - 1 - i] = a[i]; 
    }
    REP(i, N)
    {
        a[p[i]] += i;
        b[p[i]] += i;
    }

    REP(i, N)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    REP(i, N)
    {
        cout << b[i] << " ";
    }
    cout << endl;
}
