#include<bits/stdc++.h>
#define ll long long
#define ALL(v) (v).begin(),(v).end()
#define REP(i,p,n) for(int i=p;i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define dump(a) (cerr << #a << "=" << (a) << endl)
#define DUMP(list) cout << "{ "; for(auto nth : list){ cout << nth << " "; } cout << "}" << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }


using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    int a[N];
    rep(i, N){
        a[i] = 0;
    }
    rep(i, M){
        int c, b;
        cin >> c >> b;
        c--;b--;
        a[c] += 1;
        a[b] += 1;
    }

    rep(i, N){
        if (a[i] % 2 == 1) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
}