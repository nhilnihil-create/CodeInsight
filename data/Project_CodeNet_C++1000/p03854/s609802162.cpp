#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vec = vector<ll>;
using mat = vector<vec>;
using pll = pair<ll,ll>;

#define INF (1LL << 60)
#define MOD 1000000007
#define PI 3.14159265358979323846

#define REP(i,m,n) for(ll (i)=(m),(i_len)=(n);(i)<(i_len);++(i))
#define FORR(i,v) for(auto (i):v)
#define ALL(x) (x).begin(), (x).end()
#define PR(x) cout << (x) << endl
#define PS(x) cout << (x) << " "
#define SZ(x) ((ll)(x).size())
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define REV(x) reverse(ALL((x)))
#define ASC(x) sort(ALL((x)))
#define DESC(x) ASC((x)); REV((x))
#define pb push_back
#define eb emplace_back

int main()
{
    string S;
    cin >> S;

    ll N = SZ(S);
    ll k = 0;
    S += string(7, '*');
    while(k < N) {
        if(S.substr(k, 7) == "dreamer") {
            if(S.substr(k+7, 4) == "aser") k += 11;
            else if(S.substr(k+7, 3) == "ase") k += 10;
            else k += 7;
        }
        else if(S.substr(k, 5) == "dream") k += 5;
        else if(S.substr(k, 6) == "eraser") k += 6;
        else if(S.substr(k, 5) == "erase") k += 5;
        else break;
    }
    if(k == N) PR("YES");
    else PR("NO");

    return 0;
}

/*



*/