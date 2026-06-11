#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i, N) for (int i = 0; i < (int)(N); i++)

// chmax, chmin
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const ll INF = 1e+18;

int main() {
    int N,K;
    cin >> N >> K;
    vector<int> a(N);
    REP(i,N) cin >> a[i];
    
    ll ans = INF;
    for ( int bit = 0; bit < (1<<N); ++bit){
        set<int> st;
        //vector<int> S;
        for ( int i = 0; i < N; ++i){
            if ( bit & (1<<i) ) {
                st.insert(i);
                //S.push_back(i);
            }
        }
        if ( st.size() != K ) continue;
        //if ( S.size() != K ) continue;
        ll cost = 0;
        int hight = 0;
        for ( int i = 0; i < N; ++i){
            if ( st.count(i) ){
                if ( a[i] > hight ) {
                    hight = a[i];
                } else {
                    ++hight;
                    cost += ( hight - a[i] );
                }
            } else {
                if ( a[i] > hight ) hight = a[i];
                else if ( a[i] == hight ) ++ hight;
            }
        }
        //cout << cost << endl;
        chmin(ans,cost);
        //int hight = a[S[0]];
        /*for ( int i = 1; i < K; ++i){
            if ( a[S[i]] > hight ){
                hight = a[S[i]];
            } else {
                ++hight;
                cost += ( hight - a[S[i]] );
            }
        }*/
        /*cout << "bit " << bit << endl;
        for ( auto a: S) cout << a << " ";
        cout << endl;
        cout << "cost " << cost << endl;
        chmin(ans,cost);*/
    }
    cout << ans << endl;
    return 0;
}