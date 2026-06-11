#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    vector<int> cnt(7);
    int x = 0;
    rep(i,n) {
        int a;
        cin >> a;
        if(a>=3200) x++;
        else cnt[a/400]++;
    }
    int mn = 0;
    rep(i,8) {
        if(cnt[i]!=0) mn++;
    }
    if(mn==0){ cout << 1 << " " << x << endl; return 0;}
    cout << mn << " " << mn+x << endl;
    return 0;
}   