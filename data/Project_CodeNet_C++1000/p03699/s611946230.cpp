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
#include <queue>

using namespace std;
typedef long long ll;
using Graph = vector<vector<ll>>;

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

int main() {
    ll N;
    cin >> N;
    ll s[N];
    ll out = 0;
    rep(i,N){
        cin >> s[i];
        out += s[i];
    }
    sort(s,s+N);
    rep(i,N){
        if(out%10==0&&s[i]%10!=0) out -= s[i];
        if(i==N-1&&out%10==0) out = 0;
    }
    cout << out << endl;
    return 0;
}

