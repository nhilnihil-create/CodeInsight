#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <numeric>
#include <stdio.h>
#include <vector>
#include <map>

using namespace std;
typedef long long ll;

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

int main() {

    string A,B,C;
    cin >> A >> B >> C;
    ll a = A.length();
    ll b = B.length();
    ll c = C.length();
    ll i = 0;
    ll j = -1;
    ll k = -1;
    string str = A;
    string out = "";
    ll cnt = i;
    while(i<a&&j<b&&k<c){
        if(str[cnt]=='a'){
            str = A;
            out = "A";
            i++;
            cnt = i;
        }else if(str[cnt]=='b'){
            str = B;
            out  = "B";
            j++;
            cnt = j;
        }else{
            str = C;
            out = "C";
            k++;
            cnt = k;
        }
    }
    cout << out << endl;
    return 0;
}
