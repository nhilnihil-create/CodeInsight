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
    map<int,int>mp;
    rep(i,n) {
        int a;
        cin >> a;
        mp[a]++;
    }
    int ans = 0;
    for(auto i : mp) {
        if(i.second%2) ans++;
    }
    cout << ans << endl;
}