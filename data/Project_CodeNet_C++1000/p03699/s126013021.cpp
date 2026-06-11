#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}
const int mod = 1000000007;

int main() {
    int n;
    cin >> n;
    int ans = 0;
    int minv = 101;
    rep(i,n) {
        int a;
        cin >> a;
        ans += a;
        if(a%10 != 0) {
            minv = min(minv,a);
        }
    }
    
    if(ans%10==0) {
        if(minv != 101) ans -= minv;
        else ans = 0;
    } 
    cout << ans << endl;
}