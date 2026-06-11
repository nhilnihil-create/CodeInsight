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

bool not31(ll x){
    if(x == 4 || x == 6 || x == 9 || x == 11){
        return true;
    }else{
        return false;
    }
}

int main(){
    ll x, y;
    cin >> x >> y;

    ll ifSame;
    if(x == 2 || y == 2){
        ifSame = 0;
    }else if(not31(x) && not31(y)){
        ifSame = 1;
    }else if(!not31(x) && !not31(y)){
        ifSame = 1;
    }else{
        ifSame = 0;
    }

    if(ifSame == 1){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
        

    return 0;
}