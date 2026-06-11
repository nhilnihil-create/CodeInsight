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
    vector<int>cnt(9);
    rep(i,n) {
        int a;
        cin >> a;
        int rate = a/400;
        if(rate>=8)rate = 8;
        cnt[rate]++;
    }
    int minv = 0;
    int maxv = 0;
    rep(i,8) {
        if(cnt[i]) {
            minv++;
            maxv++;
        }
    }
    if(minv==0) minv++;
    maxv += cnt[8];
    cout << minv << " " << maxv << endl;
    

}