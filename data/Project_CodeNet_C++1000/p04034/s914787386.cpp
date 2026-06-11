#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <deque>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;
typedef pair<int,int> P;
int main() {

    int n,m;
    cin >> n >> m;
    
    vector<int>cnt(n+1,1);
    vector<bool>isRed(n+1, false);
    
    isRed[1] = true;
    rep(i, 0, m){
        int x,y;
        cin >> x >> y;
        if(isRed[x]){
            isRed[y] = true;
        }
        cnt[x]--;
        cnt[y]++;
        if(cnt[x] == 0) isRed[x]=false;
    }
    ll ans = 0;
    rep(i, 0, n){
        if(cnt[i+1] !=0 && isRed[i+1]) ans++;
    }
    cout << ans << endl;
    return 0;
}
