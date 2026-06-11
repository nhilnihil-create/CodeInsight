#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

int main() {
    int n;
    ll k;
    cin >> n >> k;
    vector<pair<int,int>>s;
    rep(i,n) {
        int a,b;
        cin >> a >> b;
        s.push_back(make_pair(a,b));
    }
    sort(s.begin(),s.end());
    ll sum = 0;
    int ans = 0;
    rep(i,n) {
        sum += s[i].second;
        if(sum >= k) {
            ans = s[i].first;
            break;
        }
    }
    cout << ans << endl;
    
}