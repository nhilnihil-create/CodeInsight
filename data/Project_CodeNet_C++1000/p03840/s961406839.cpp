#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <iostream>
#include <set>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

typedef long long int ll;
typedef pair<int, int> Pii;
typedef pair<int, double> Pid;
typedef pair<double, int> Pdi;
typedef pair<double, double> Pdd;
typedef pair<ll, ll> P;

const int mod = 1e9+7;
const int INF = 2e9;
const double epsilon = 1e-7;
const double PI = 3.1415926535;

ll mi(ll x, ll y){
    if(x<y)return x;
    return y;
}

int main(void){
    ll I, O, T, J, L, S, Z; cin >>I>>O>>T>>J>>L>>S>>Z;
    ll ans = O;
    if(I == 0){
        cout << ans + J/2*2 + L/2*2 << endl;
        return 0;
    }
    if(J == 0){
        cout << ans + I/2*2 + L/2*2 << endl;
        return 0;
    }
    if(L == 0){
        cout << ans + J/2*2 + I/2*2 << endl;
        return 0;
    }
    if(I%2+J%2+L%2 == 3){
        cout << ans + I+J+L << endl;
        return 0;
    }
    if(I%2+J%2+L%2 == 2){
        cout << ans + I/2*2 + J/2*2 + L/2*2 + 1 << endl;
        return 0;
    }
    cout << ans + I/2*2 + J/2*2 + L/2*2 << endl;
	return 0;
}
