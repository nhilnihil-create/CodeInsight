#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

int main() {
    int n,m;
    cin >> n >> m;
    vector<int>a(n),b(n);
    vector<int>c(m),d(m);
    rep(i,n) cin >> a[i] >> b[i];
    rep(i,m) cin >> c[i] >> d[i];
    vector<int>dist(n);
    rep(i,n) {
        int tmp = 1e9;
        rep(j,m) {
            tmp = min(tmp,abs(a[i]-c[j])+abs(b[i]-d[j]));
        }
        dist[i] = tmp;
    }
    rep(i,n) {
        int tmp = 1e9;
        rep(j,m) {
            tmp = min(tmp,abs(a[i]-c[j])+abs(b[i]-d[j]));
            if(dist[i] == tmp) {
                cout << j+1 << endl;
                break;
            }                
        }
    }
}