#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int cnt[9];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    rep(i,n){
        int a;
        cin >> a;
        if(a >= 3200) cnt[8]++;
        else cnt[a/400]++;
    }
    int mi = 0, ma = 0;
    rep(i,8){
        if(cnt[i] > 0){
            ++mi;
            ++ma;
        }
    }
    ma += cnt[8];
    chmax(mi, 1);
    cout << mi << " " << ma << endl;
    return 0;
}
