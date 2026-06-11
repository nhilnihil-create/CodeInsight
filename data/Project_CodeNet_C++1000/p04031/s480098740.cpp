#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,N) for(int i = 0; i < (N); i++)

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

const long long INF = 1LL << 60;

//入力
double N;
int cnt,ans = 10000000;
int a[150];


int main(){
    cin >> N;
    rep (i,N) {
        cin >> a[i];
    }
    for (int i = -100; i <= 100; i++){
        cnt = 0;
        rep (j,N){
            cnt += pow(abs(a[j] - i),2);
        }
        ans = min(ans,cnt);
    }
    cout << ans << endl;
}
