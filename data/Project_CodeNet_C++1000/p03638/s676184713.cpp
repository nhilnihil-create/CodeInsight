#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstdlib>
#include <vector>
#include <iomanip>
#include <utility>
using namespace std;
#define ll long long

int main(void){
    ll h, w;
    cin >> h >> w;
    ll n;
    cin >> n;
    ll a[n];
    ll count = 0;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        count += a[i];
    }
    ll ans[h][w];
    ll check = 1; ll cc = 0;
    for(ll i = 0; i < h; i++){
        for(ll j = 0; j < w; j++){
            ans[i][j] = check;
            cc++;
            if(cc==a[check-1]){
                cc=0;
                check++;
            }
        }
    }
    for(ll i = 1; i < h; i+=2){
        for(ll j = 0; j < w/2; j++){
            swap(ans[i][j], ans[i][w-j-1]);
            //cout << ans[i][j] << " " << ans[i][w-j] << endl;
        }
        
    }
    for(ll i = 0; i < h; i++){
        for(ll j = 0; j < w; j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
    return 0;
}