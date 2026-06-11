#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

#define rep(i, n) for(ll i = 0; i < n; i++)
#define REP(i, n) for(ll i = 1; i < n + 1; i++)
#define PI 3.14159265359
#define EPS 0.0000000001
#define MOD 1000000007
//cout << std::fixed << std::setprecision(15) << y << endl;


int main(){
    ll N;
    cin >> N;

    ll a;
    ll color[9];
    rep(i, 9){
        color[i] = 0;
    }
    rep(i, N){
        cin >> a;
        if(a <= 399){
            color[0]++;
        }else if(a <= 799){
            color[1]++;
        }else if(a <= 1199){
            color[2]++;
        }else if(a <= 1599){
            color[3]++;
        }else if(a <= 1999){
            color[4]++;
        }else if(a <= 2399){
            color[5]++;
        }else if(a <= 2799){
            color[6]++;
        }else if(a <= 3199){
            color[7]++;
        }else{
            color[8]++;
        }
    }

    ll ans = 0;
    rep(i, 8){
        if(color[i] > 0){
            ans++;
        }
    }

    if(ans == 0){
        if(color[8] != 0){
            cout << 1 << " " << color[8] << endl;
        }else{
            cout << "0 0" << endl;
        }
    }else{
        cout << ans << " " << ans + color[8] << endl;
    }

    return 0;
}