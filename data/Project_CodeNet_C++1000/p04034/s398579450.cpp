#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int inf = 1001001001;
vector<int> dx = {1,0,-1,0};
vector<int> dy = {0,1, 0,-1};

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> box(n,1), box_red(n,0);
    box_red.at(0) = 1;
    
    rep(i,m) {
        int x,y;
        cin >> x >> y;
        x--; y--;
        box.at(x)--;
        box.at(y)++;
        if(box_red.at(x) == 1) box_red.at(y) = 1;
        if(box.at(x) == 0) box_red.at(x) = 0;
    }
    
    int ans = 0;
    rep(i,n) {
        ans += box_red.at(i);
        //cout << box_red.at(i) << endl;
    }
    cout << ans << endl;
}