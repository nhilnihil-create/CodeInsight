#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    ll N, K;
    cin >> N >> K;
    map<int, ll> mp;
    rep(i, N){
        int a, b;
        cin >> a >> b;
        mp[a] += b;
    }
    ll sum = 0;
    int ans;
    for(auto p : mp){
        sum += p.second;
        if(sum >= K){
            ans = p.first;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}