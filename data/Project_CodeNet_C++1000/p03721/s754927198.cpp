#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <random>
#include <cstdio>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int) n; i++)

int main() {
    ll n,k;
    cin >> n >> k;
    ll a,b;
    vector<ll> cnt(1e6);
    rep(i,n) {
        cin >> a >> b;
        cnt[a-1] += b;
    }
    ll cum = 0;
    for (int i = 0; i < 1e6; i++)
    {
        cum += cnt[i];
        if (cum >= k) {
            cout << i+1 << endl;
            return 0;
        }
    }    
    return 0;
}