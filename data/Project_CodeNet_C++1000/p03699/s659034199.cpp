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
    vector<int>a(n);
    rep(i,n) cin >> a[i];
    vector<int>s(n+1);
    rep(i,n) s[i+1] = a[i]+s[i];
    
    vector<int>ans;
    rep(i,n+1) rep(j,i) {
        int tmp = s[i] - s[j];
        ans.push_back(tmp);
    }
    for(int i = 1;i<=n;i++) {
        rep(j,n) {
            int tmp = s[i]-a[j];
            ans.push_back(tmp);
        }
    }
    sort(ans.rbegin(),ans.rend());
    
    int score = 0;
    rep(i,ans.size()) {
        if(ans[i]%10 != 0) {
            score = ans[i];
            break;
        }
    }
    cout << score << endl;

}