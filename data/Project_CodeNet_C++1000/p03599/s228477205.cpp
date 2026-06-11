#include <bits/stdc++.h>
#define itn int
#define REP(i, n) for (ll i = 0; i <= n; i++)
#define IREP(i, n) for (ll i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for (ll i = a; i < b + 1; i++)
#define all(v) v.begin(), v.end()
#define SENTINEL 2000000000
#define NIL -1
using namespace std;
typedef long long ll;

const ll MAX = 510000;
const ll INF = 1LL << 60;
const ll MOD = 1000000007;
template <class T>inline bool chmin(T &a, T b){if(a>b){a=b;return true;}return false;}
template <class T>inline bool chmax(T &a, T b){if(a<b){a=b;return true;}return false;}


int main()
{
    int a,b,c,d,e,f;
    cin >> a >> b >> c >> d >> e >> f;
    double maxnoudo=-1;
    int ansmizu=0;
    int anssugar=0;
    REP(i,f/(a*100)){
        REP(j,(f-i*a*100)/(b*100)){
            if(i==0&&j==0){
                continue;
            }
            int mizu=a*100*i+b*100*j;
            int maxsugar=min(f-mizu,mizu*e/100);
            int sugar=0;
            REP(z,maxsugar/c){
                int tmp=z*c+((maxsugar-z*c)/d)*d;
                chmax(sugar,tmp);
            }
            if(double(sugar)*100/double(sugar+mizu)>maxnoudo){
                maxnoudo = double(sugar) * 100 / double(sugar + mizu);
                ansmizu=mizu+sugar;
                anssugar=sugar;
            }
        }
    }
    cout << ansmizu << " " << anssugar << endl;
}
