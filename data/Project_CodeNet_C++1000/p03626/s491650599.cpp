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

int MOD = 1e9+7;

signed main() {
    int N;
    cin >> N;
    string s1, s2;
    cin >> s1 >> s2;

    int i=0;
    bool prev = false;
    int res = 1;
    if(s1[i]==s2[i]) {i=1; prev = true; res*=3;}
    else {i=2; res*=6;}
    while(i<N) {
        if(s1[i]==s2[i]) {
            if(prev) res *= 2;
            prev = true;
            i++;
        } else {
            if(prev) res *= 2;
            else res *= 3;
            prev = false;
            i+=2;
        }
        res %= MOD;
    }
    
    cout << res << endl;
    return 0;
}