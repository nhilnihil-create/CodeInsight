#include <algorithm>
#include <iostream> //標準入出力
#include <fstream>  //ファイルでの入出力
#include <vector>
#include <set>
#include <functional>
#include <string>
#include <utility> //pair
#include <cmath>  //sqrt 
#include <iomanip> //setprecision
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define ALL(a)  (a).begin(),(a).end()
#define MAX 1000000
#define pair(a) pair<a,a>

void _main(){
    ll out = __LONG_LONG_MAX__;
    int n,k; cin >> n >> k;
    vector<ll> heights(n); rep(i,n) cin >> heights[i];
    for (int bit = 0; bit < (1<<(n-1)); bit++)
    {
        vector<ll> heightscopy = heights;
        int color=1;
        ll sum = 0;
        ll maxheight_onleftside = heightscopy[0];
        rep(i,n-1){
            if(bit&(1<<i)){
                color++;
            }
        }
        if(color>=k){
            rep(i,n-1){
                int j = i+1;
                if(bit&(1<<i)){
                    if(maxheight_onleftside+1 > heightscopy[j]){
                        sum += maxheight_onleftside+1 - heightscopy[j];
                        heightscopy[j] = maxheight_onleftside+1;
                    }
                }
                maxheight_onleftside = max(maxheight_onleftside,heightscopy[j]);
            }
            out = min(sum,out);
        }
    }
    
    cout<< out << endl;
    return;
}
int main() {
    cout << fixed << setprecision(10);
    _main();
    return 0;
}
    