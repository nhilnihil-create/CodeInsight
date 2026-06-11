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
    string Sa, Sb, Sc;
    cin >> Sa >> Sb >> Sc;

    REV(Sa); REV(Sb); REV(Sc);
    char x = Sa.back();
    Sa.pop_back();
    while(true) {
        if(x == 'a') {
            if(SZ(Sa) > 0) {
                x = Sa.back();
                Sa.pop_back();
            }
            else {
                PR("A");
                break;
            }
        }
        if(x == 'b') {
            if(SZ(Sb) > 0) {
                x = Sb.back();
                Sb.pop_back();
            }
            else {
                PR("B");
                break;
            }
        }
        if(x == 'c') {
            if(SZ(Sc) > 0) {
                x = Sc.back();
                Sc.pop_back();
            }
            else {
                PR("C");
                break;
            }
        }
    }

    return 0;
}

/*



*/