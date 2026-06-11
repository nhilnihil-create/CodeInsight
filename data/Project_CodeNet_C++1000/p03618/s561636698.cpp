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
    string A;
    cin >> A;
    ll m[27];

    rep(i, 27){
        m[i] = 0;
    }
    rep(i, A.size()){
        m[A[i] - 'a']++;
    }
    ll ans = (A.size()*(A.size()-1))/2;
    rep(i, 27){
        ans -= (m[i]*(m[i]-1))/2;
    }
    cout << ans +1 << endl;
};