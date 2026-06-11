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
    cin >> n >> m;
    string a[n],b[m];
    rep(i,n) cin >> a[i];
    rep(i,m) cin >> b[i];
    bool next = false;
    rep(i,n-m+1){
        rep(j,n-m+1){
            next = false;
            rep(v,m){
                rep(u,m){
                    if(a[i+v][j+u] != b[v][u]) next = true;
                    if(next) break;
                }
                if(next) break;
            }
            if(!next){
                cout << "Yes" << endl;
                return 0;
            }

        }
    }
    cout << "No" << endl;
    return 0;
}