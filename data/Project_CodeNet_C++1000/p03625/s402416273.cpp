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
    vector<int>edge1;
    for(auto i : mp) {
        if(i.second >= 2)edge1.push_back(i.first);
    }
    sort(edge1.rbegin(),edge1.rend());
    ll ans1 = 0;
    if(edge1.size() >= 2) {
        ans1 = (ll)(edge1[0]) * (ll)(edge1[1]); // 正方形でないとき
    }
    vector<int>edge2;
    ll ans2 = 0;
    for(auto i : mp) {
        if(i.second >= 4) edge2.push_back(i.first);
    }
    sort(edge2.rbegin(),edge2.rend());
    if(edge2.size() >= 1) {
        ans2 = (ll)(edge2[0]) * (ll)(edge2[0]); // 正方形のとき
    }
    if(ans1 == 0 && ans2 == 0) {
        cout << 0 << endl;
        return 0;
    }
    cout << max(ans1,ans2) << endl;

    
    


}