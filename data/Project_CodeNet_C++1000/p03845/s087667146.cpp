#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define MIN(a,b) ((a)>(b)? (b): (a))
#define MAX(a,b) ((a)<(b)? (b): (a))

const long long INF = 1LL << 60;
typedef unsigned long long ll;
const long long MOD = 1000000000 + 7;

int main(){
    int n,m;
    cin >> n;
    int T[n];
    rep(i,n) cin >> T[i];
    cin >> m;
    int P[m],X[m];
    rep(i,m) cin >> P[i] >> X[i];
    rep(i,m){
        ll out = 0;
        rep(j,n){
            if(j==P[i]-1) out += X[i];
            else out += T[j];
        }
        cout << out << endl;
    }
    return 0;
}