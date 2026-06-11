#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64
#define rep(i, n) for(int i=0; i<n; i++)
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define SORT(x) sort(x.begin(), x.end())
#define GSORT(x) sort(x.begin(), x.end(), greater<int>())
#define mk make_pair
#define fi first
#define se second
#define pb push_back
#define ALL(x) x.begin(), x.end()
#define V(T) vector<T>
typedef pair<int, int> P;
typedef pair<P, P> PP;
typedef vector<int> vi;
typedef vector<vi> vvi;
int max(int a, int b) {if(b>a) return b; else return a;}
int min(int a, int b) {if(b<a) return b; else return a;}

const int MOD = 1e9+7;
const int MX = 1050;
V(bool) isp(MX, true);
vi pns;

void pjudge() {
    isp[0]=isp[1]=false;
    for(int i=2; i*i<MX; i++) {
        if(!isp[i]) continue;
        for(int j=i*2; j<MX; j+=i) {
            isp[j] = false;
        }
    }
    rep(i, MX) if(isp[i]) pns.pb(i);
}

void countp(int n, map<int, int> &mp) {
    int m = pns.size();
    rep(i, m) {
        while(n%pns[i]==0) {
            mp[pns[i]]++;
            n /= pns[i];
        }
    }
}

signed main() {
    int N;
    cin >> N;

    pjudge();
    map<int, int> mp;
    FOR(i, 1, N+1) countp(i, mp);

    int res = 1;
    for(auto &p : mp) {
        res *= p.se+1;
        res %= MOD;
    }

    cout << res << endl;
    
    return 0;
}