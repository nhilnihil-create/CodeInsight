#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}


int main() {
    int n;
    cin >> n;
    vector<int>a(n);
    rep(i,n) cin >> a[i];
    //偶数番目が正、奇数番目が負の場合
    ll sum = 0;
    ll ans = 1e18;
    ll tmp = 0;
    rep(i,n) {
        sum += a[i];
        if(i%2==0 && sum <=0) {
            tmp += abs(sum)+1;
            sum = 1;
        } else if(i%2==1 && sum>=0) {
            tmp += sum+1;
            sum = -1;
        }
    }
    ans = min(ans,tmp);
    //偶数番目が負、奇数番目が正の場合
    sum = 0;
    tmp = 0;
    rep(i,n) {
        sum += a[i];
        if(i%2==0 && sum >=0) {
            tmp += abs(sum)+1;
            sum = -1;
        } else if(i%2==1 && sum<=0) {
            tmp += abs(sum)+1;
            sum = 1;
        }
    }
    ans = min(ans,tmp);
    cout << ans << endl;

}