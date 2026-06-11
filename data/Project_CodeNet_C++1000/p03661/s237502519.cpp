#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cstring>
#include<iomanip>
using namespace std;
typedef long long lng;
typedef unsigned long long ulng;

#define pb push_back
#define SZ(a) int((a).size())
#define ALL(a) (a).begin(), (a).end()
#define FOR(i,a,b) for(int i=(a); i<=(b); ++i)
#define FORD(i,b,a) for(int i=(b); i>=(a); --i)
#define REP(i,n) FOR(i,0,n-1)
#define UNIQUE(a) a.erase(unique(ALL(a)), a.end())

lng power(lng b, lng e) {lng sol=1; while(e>0) {if(e&1) {sol=sol*b;} e>>=1; b*= b;} return sol;}

int N;
lng sum[200010];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    REP(i, N) {
        cin >> sum[i];
        if(i > 0) sum[i] += sum[i-1];
    }

    lng ans = 1LL << 40;
    FOR(i, 0, N-2) {
        lng x = sum[i];
        lng y = sum[N-1] - sum[i];
        ans = min(ans, max(x-y, y-x));
    }
    cout << ans << endl;
}
