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
    ll N, L;
    cin >> N >> L;
    ll a[N];
    rep(i, N){
        cin >> a[i];
    }

    bool flag = false;
    int ind = -1;
    rep(i, N-1) {
        if (a[i] + a[i+1] >= L) {
            flag = true;
            ind = i;
        }
    }

    if (!flag) {
        cout << "Impossible" << endl;
        return 0;
    } else {
        cout << "Possible" << endl;
    }

    rep(i, ind) {
        cout << i + 1 << endl;
    }

    for (int i = N - 2; i > ind; i--) {
        cout << i + 1 << endl;
    }


    cout << ind + 1<< endl;


}