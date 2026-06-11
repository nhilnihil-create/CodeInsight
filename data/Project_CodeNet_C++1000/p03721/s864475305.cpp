#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using P = pair<int, int>;

#define roop(i, n) for(int i = 0;i < n;i++)

int main(void){

    int n;
    ll k;
    cin >> n >> k;
    map<int, ll> mp;

    roop(i, n){
        int a, b;
        cin >> a >> b;
        mp[a] += b;
    }

    ll tmp = k;
    for(auto a: mp){
        tmp -= a.second;
        if(tmp <= 0){
            cout << a.first << endl;
            return 0;
        }
    }

    return 0;
}
