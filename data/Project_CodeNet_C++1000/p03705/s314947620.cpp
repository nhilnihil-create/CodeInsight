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

    ll N,A,B;
    cin >> N >> A >> B;
    ll out = 0;
    if(N==1){
        if(A==B) out = 1;
    }
    else if(B<A);
    else out = (N-2)*(B-A)+1;
    cout << out << endl;
    return 0;
}
