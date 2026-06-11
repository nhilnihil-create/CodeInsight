#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <queue>
#include <string>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int> ;
using vl = vector<ll>;

int main(){
    int x,y;
    cin >> x >> y;
    int ans = 2e9+10;
    int tx = x,ty = y;

    if(tx <= ty){
        ans = min(ans,ty-tx);
    }
    tx = -x;
    if(tx <= ty){
        ans = min(ans,ty-tx+1);
    }
    tx = x;
    ty = -y;
    if(tx <= ty){
        ans = min(ans,ty-tx+1);
    }
    tx = -x;
    ty = -y;
    if(tx <= ty){
        ans = min(ans,ty-tx+2);
    }

    cout << ans << endl;
    return 0;
}